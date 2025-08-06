#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <limits>

using namespace std;

class Bill
{
private:
  string Item;
  int Rate, Quantity;

public:
  Bill() : Item(""), Rate(0), Quantity(0) {}

  void setItem(string item) { Item = item; }
  void setRate(int rate) { Rate = rate; }
  void setQuant(int quant) { Quantity = quant; }

  string getItem() { return Item; }
  int getRate() { return Rate; }
  int getQuant() { return Quantity; }
};

void addItem(Bill &b)
{
  bool close = false;

  while (!close)
  {
    int choice;
    cout << "\n1. Add Item\n2. Close\nEnter Choice: ";
    cin >> choice;

    if (choice == 1)
    {
      cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Flush newline

      string item;
      int rate, quant;

      cout << "Enter Item Name: ";
      getline(cin, item);
      b.setItem(item);

      cout << "Enter Rate of Item: ";
      cin >> rate;
      b.setRate(rate);

      cout << "Enter Quantity of Item: ";
      cin >> quant;
      b.setQuant(quant);

      ofstream out("Bill.txt", ios::app);
      if (!out)
      {
        cout << "Error: Could not open file!" << endl;
      }
      else
      {
        out << item << ":" << rate << ":" << quant << endl;
        cout << "Item added successfully!\n";
      }
      out.close();
    }
    else if (choice == 2)
    {
      close = true;
      cout << "Returning to main menu...\n";
    }
    else
    {
      cout << "Invalid choice!\n";
    }
  }
}

void printBill()
{
  int total = 0;
  bool close = false;

  while (!close)
  {
    int choice;
    cout << "\n1. Add Bill Item\n2. Close Session\nEnter Choice: ";
    cin >> choice;

    if (choice == 1)
    {
      cin.ignore(numeric_limits<streamsize>::max(), '\n');

      string item;
      int quant;

      cout << "Enter Item Name: ";
      getline(cin, item);

      cout << "Enter Quantity: ";
      cin >> quant;

      ifstream in("Bill.txt");
      ofstream out("Bill_temp.txt");

      if (!in || !out)
      {
        cout << "File error!" << endl;
        return;
      }

      string line;
      bool found = false;

      while (getline(in, line))
      {
        stringstream ss(line);
        string itemName;
        int itemRate, itemQuant;
        char delim1, delim2;

        getline(ss, itemName, ':');
        ss >> itemRate >> delim1 >> itemQuant;

        if (item == itemName)
        {
          found = true;
          if (quant <= itemQuant)
          {
            int amount = itemRate * quant;
            cout << "Item: " << itemName << " | Rate: " << itemRate
                 << " | Quantity: " << quant << " | Amount: " << amount << endl;

            int remaining = itemQuant - quant;
            if (remaining > 0)
            {
              out << itemName << ":" << itemRate << ":" << remaining << endl;
            }
            total += amount;
          }
          else
          {
            cout << "Not enough stock for " << itemName << "!" << endl;
            out << line << endl; // write unchanged line
          }
        }
        else
        {
          out << line << endl;
        }
      }

      if (!found)
      {
        cout << "Item not found in inventory!" << endl;
      }

      in.close();
      out.close();

      remove("Bill.txt");
      rename("Bill_temp.txt", "Bill.txt");
    }
    else if (choice == 2)
    {
      close = true;
      cout << "\nTotal Bill Amount: " << total << endl;
      cout << "Thank you for shopping!\n";
    }
    else
    {
      cout << "Invalid choice!\n";
    }
  }
}

int main()
{
  Bill b;
  bool exit = false;

  while (!exit)
  {
    int choice;
    cout << "\n====== Inventory Billing ======\n";
    cout << "1. Add Item\n2. Print Bill\n3. Exit\nEnter your choice: ";
    cin >> choice;

    switch (choice)
    {
    case 1:
      addItem(b);
      break;
    case 2:
      printBill();
      break;
    case 3:
      cout << "Exiting system. Goodbye!\n";
      exit = true;
      break;
    default:
      cout << "Invalid choice. Try again.\n";
    }
  }

  return 0;
}
