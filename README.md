# Computing II Final Project
By: Damanveer Singh

### Overview
This project is seeking to create a Banking System with core features of a bank (accounts, deposits, withdrawals, etc.). The information collected will be stored in classes and saved in hidden files with encrypted names on the user’s computer. Classes are the main data structure used to manage data in this program.

### Usage
Anyone in modern day would have to store their money in some way. Very few people keep all their money and protect it by themselves. Most often, the money is stored in a trusted banking system. Thus, this program is targeted at basically anyone in a modern society.

### Issues Addressed
Having an online bank allows people to better analyze their financial status and view previous transactions and balances. By having an easy-to-access system that can be used from anywhere, including your home, many people will be more likely to store their money with a bank rather than at home under their mattress.

### Security Features
To protect the user’s information when they log out of their account, a data security method is needed. I will be using the user’s information to generate a hashed key that can be used to locate the user’s saved information file. The hash uses a symmetric hashing algorithm to better create a consistency in user access and prevent user’s from accessing other save files by accident.

### Algorithm
The user will first be prompted to log in or create a new account. Once the information is retrieved then the user’s accounts will calculate the interest accumulated since the last time the account was accessed by comparing the last login date and the current time. From here, the user can use any banking features such as deposits, withdrawals, checking balance, opening/closing accounts and viewing statements. The program also asks the user how much money they have on hand at the beginning of the program to better validate deposits to the account.

### Data Collected
For this banking program, I will be collecting data about the user and logging said info. This will information includes basic identity info like name, address, and date of birth as well as data regarding account transactions, logins, logouts, and account balances. The user is also able to view banking statements so the transaction amounts and dates will all be logged as well.

## Classes Explained
### Bank
The Bank class is the main handler for the program and controls all of the user interface aspects of the program. Through this class, the user can check their account balance, deposit / withdraw money, and view their log files. When this class is first instantiated, it will ask the user to log in or create a new account. This information will be used to retrieve and old save files that may exist.

### User
Every user of the program must create an account with the bank in order to save their information. The User class holds the user’s name, address, birth date, password, and checking account information. This class is also used to generate the key to find save files for the user. When creating a new account, the Bank class will handle all information gathering required and just pass it into the User class’s constructor to be extracted.

### Account
The user is currently allowed to have only 1 type of account, a checking account. However, if a different type of account was needed, the abstract Account class can be easily implemented and in order to derive the main functions of an account (deposit, withdraw, balance). The CheckingAccount class is just an extension of this class.
