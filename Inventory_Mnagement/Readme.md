📦 Inventory Management System
A console-based Inventory Management and Billing System written in C++ that allows users to:

Add new items to the inventory

Generate bills for customers

Automatically update inventory stock after billing

📋 Features
🔐 Add Items: Input product name, price, and quantity to maintain inventory.

🧾 Print Bills: Select items from the inventory to generate a bill.

📉 Automatic Stock Update: Automatically decreases inventory after billing.

📁 Persistent Storage: Uses Bill.txt to store inventory data locally.

🛠️ Tech Stack
Language: C++

File Handling: Uses text files for storing and updating inventory

Compiler: Any standard C++ compiler (G++, MSVC, etc.)

📂 File Structure
bash
Copy
Edit
Inventory_Management/
│
├── InventoryManagementSystem.cpp   # Main source code
├── Bill.txt                        # Inventory database (auto-generated)
└── README.md                       # Documentation
💻 How to Run
🧱 Prerequisites
C++ compiler installed (e.g., g++)

Terminal / Command Prompt access

🏃 Steps to Run
Clone or Download this repository.

Compile the code:

g++ InventoryManagementSystem.cpp -o inventory


Run the program:

./inventory


✅ Usage Instructions
1️⃣ Add Item
Select "Add Item"

Enter item name, rate, and quantity

The item will be saved in Bill.txt

2️⃣ Print Bill
Choose items to sell

Enter quantity required

Bill will be printed

Inventory will be updated

📘 Sample Inventory File (Bill.txt)
makefile
Copy
Edit
Milk:50:20
Bread:30:15
Eggs:6:100
Each line is in the format: ItemName:Rate:Quantity

⚠️ Limitations
Not thread-safe (single-user CLI app)

No advanced error logging

Uses plain .txt file (no DB or encryption)

🚀 Future Improvements
Use CSV or SQLite for inventory data

GUI interface (using Qt or Tkinter with Python)

Export bill as PDF

Add login/authentication system

👤 Author
Sarthak Chauhan
Final Year B.Tech, NIT Hamirpur
Interest: C++, DSA, Frontend
