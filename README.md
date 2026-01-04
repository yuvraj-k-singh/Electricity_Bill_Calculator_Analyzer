# Electricity Bill Calculator & Analyzer

## 📌 Project Overview

**Electricity Bill Calculator & Analyzer** is a menu-driven C programming project designed to manage electricity billing for multiple consumers. The project allows users to add consumers, calculate electricity bills using slab-based tariff rates, analyze monthly consumption, and store/load data using text files.

This project demonstrates the implementation of a real-life electricity billing system using structured and modular C programming.

---

## 🛠️ Technologies Used

* **Programming Language:** C
* **Concepts Applied:**

  * Structures
  * Arrays
  * Functions
  * Conditional statements
  * Loops
  * File Handling (TXT files)
  * String handling

---

## 📂 Project Features

### 1️⃣ Add New Consumer

* Add multiple consumers
* Store consumer name, room number, and meter number
* Prevent duplicate consumer entries

### 2️⃣ Calculate Bill

* Calculate electricity bill based on unit consumption
* Uses slab-based tariff rates
* Adds fixed charge and meter rent

### 3️⃣ Add New Bill

* Assign monthly electricity units to a specific consumer
* Automatically calculate and store bill amount

### 4️⃣ Analyze Monthly Bill

* Identify consumer with:

  * Maximum electricity usage
  * Minimum electricity usage
* Display room number, units consumed, and bill amount

### 5️⃣ Data Persistence

* Save consumer and billing data into a `.txt` file
* Load stored data when the program restarts

### 6️⃣ Power Saving Tips

* Displays basic electricity-saving suggestions

---

## 📊 Electricity Tariff Structure

| Units Consumed | Rate (Rs/unit) |
| -------------- | -------------- |
| 0 – 50         | 4.27           |
| 51 – 150       | 5.23           |
| 151 – 300      | 6.61           |
| 301+           | 6.80           |

**Additional Charges:**

* Fixed Charge: Rs 50.00
* Meter Rent: Rs 10.00

---

## 📁 File Handling

* **File Type:** `.txt`
* Used to store:

  * Consumer details
  * Monthly unit consumption
  * Bill amount
* Ensures data persistence across program runs

---

## ▶️ How to Run the Project

1. Clone the repository:

   ```bash
   git clone https://github.com/yuvraj-k-singh/Electricity_Bill_Calculator_Analyzer.git
   ```
2. Navigate to the project directory
3. Compile the program:

   ```bash
   gcc Electricity\ Bill\ Calculator\ \&\ Analyzer.c -o bill
   ```
4. Run the program:

   ```bash
   ./bill
   ```

---

## 📌 Menu Options

```
1. Add New Consumer
2. Calculate Bill
3. Analyze Monthly Bill
4. Add New Bill
5. Power Saving Tips
6. Exit
```

---

## 📚 Learning Outcomes

* Improved understanding of C structures and arrays
* Hands-on experience with file handling
* Stronger logical and analytical thinking
* Experience in building a real-life use case project

---

## 🚀 Future Enhancements

* Login system (Admin/User)
* Monthly bill history
* Graphical User Interface (GUI)
* Export bills to PDF
* Database integration

---

## 👨‍💻 Developer

**Yuvraj Kumar Singh**

---

## 🤝 Contributing
Contributions, issues, and feature requests are welcome!

Process:
1. Fork the repository
2. Create a new branch
3. Commit your changes
4. Submit a pull request

---

## 📜 License
This project is open-source and available under the **MIT License**.

---

### ⭐ If you find this project helpful, please give it a star!
