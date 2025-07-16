
# 🏥 Clinic Management System in C

This is a simple terminal-based **Clinic Management System**, developed in the C programming language as part of the **Embedded Systems Track** at the **National Telecommunication Institute (NTI)**.

The project simulates basic operations of a small clinic, allowing the admin to manage patient records and appointment bookings, and providing users with access to view available slots and patient data.

---

## 🚀 Project Summary

- **Language:** C
- **Interface:** Terminal / Command-Line
- **Data Handling:** Dynamic (via Linked List)
- **Storage:** In-memory (no database or file storage)

---

## 🔧 Features

### 👨‍⚕️ Admin Mode (Password Protected)
- Add new patient records (Name, Age, Gender, ID)
- Edit existing patient details
- Reserve appointment slots from 5 predefined options
- Cancel reservations
- Secure login with password (default: `1234`)

### 👤 User Mode
- View patient record by ID
- View available and reserved appointment slots

---

## 🧠 Concepts Used

- Structured programming in C
- User-defined data types using `struct`
- Dynamic memory allocation (`malloc`)
- Linked list data structure for storing patients
- Function modularity and separation of logic
- Conditional structures and loops
- Terminal-based interaction and input handling

---

## 🗂️ File Structure

```
.
├── main.c         # Entry point and mode selection logic
├── clinic.c       # All core functions (add, edit, reserve, etc.)
├── clinic.h       # Struct definition and function declarations
├── README.md      # Project documentation
```

---

## 🖥️ How to Run the Program

### ✅ If using GCC:

1. Open terminal in project directory  
2. Compile:
   ```bash
   gcc main.c clinic.c -o clinic
   ```
3. Run:
   ```bash
   ./clinic
   ```

---

## 📌 Appointment Slots

- 1) 2:00 PM - 2:30 PM  
- 2) 2:30 PM - 3:00 PM  
- 3) 3:00 PM - 3:30 PM  
- 4) 4:00 PM - 4:30 PM  
- 5) 4:30 PM - 5:00 PM

Once a slot is reserved, it becomes unavailable for other patients.

---


## 🙋‍♀️ Author

**Sama Yasin**  
Electronics & Communications Engineering Student  
Embedded Systems Learner – NTI  
This is my **first complete C project**, and it helped me apply what I’ve learned in a real-world simulation.

---

## 📎 License

This project was developed for learning purposes.  
Feel free to use, fork, and build on it with credit.


