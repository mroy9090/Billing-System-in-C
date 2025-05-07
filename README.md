# 💰 Billing System in C

A simple and efficient billing system built using the **C programming language**, designed for use in small to medium-sized super shops or retail stores.

---

## 🧾 Project Overview

This billing system allows shopkeepers to:
- Manage product inventory
- Process customer purchases
- Calculate bills automatically
- Maintain payment history and product data in files

The project uses file handling in C to store and retrieve information from `product.txt` and `paymentData.txt`.

---

## 📦 Files in the Repository

| File Name         | Description                                    |
|------------------|------------------------------------------------|
| `project.c`       | Main source code for the billing system       |
| `project.o`       | Compiled object file (auto-generated)         |
| `project.exe`     | Executable file for running the project       |
| `product.txt`     | Contains product data (name, price, quantity) |
| `paymentData.txt` | Stores billing/payment records                |
| `README.md`       | Project documentation                         |

---

## 🛠️ Features

- Add new products to inventory
- Display available products
- Search products by name
- Generate customer bills
- Record and store payment history
- Simple and clear command-line interface

---

## 🚀 Getting Started

### 💻 Compilation (Linux/Windows with GCC)

```bash
gcc project.c -o billing_system
./billing_system

