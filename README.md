# ATM Program

Welcome to the ATM Program! This program simulates an Automated Teller Machine (ATM) system where users can perform various banking transactions such as depositing money, withdrawing money, checking their balance, viewing transaction history, and transferring money between accounts.

## How to Use

1. Run the program.
2. Choose from the options provided in the menu to perform different actions.
3. Follow the on-screen instructions to input necessary information, such as amounts for deposit, withdrawal, and transfer, as well as selecting the recipient for a transfer.

## Features

- **Show Balance**: View the current balance of the active user.
- **Withdraw Amount**: Withdraw money from the active user's account.
- **Deposit Amount**: Deposit money into the active user's account.
- **Transaction History**: View the transaction history of the active user, including deposits, withdrawals, and transfers.
- **Switch User**: Toggle between two user accounts.
- **Transfer Money**: Transfer money from the active user's account to another user's account.

## Class Structure

The program is structured around the `ATM` class, which represents a user's bank account. It has the following methods:

- `deposit(int amount)`: Deposits a specified amount of money into the account.
- `withdraw(int amount)`: Withdraws a specified amount of money from the account.
- `getBalance()`: Retrieves the current balance of the account.
- `showHistory()`: Displays the transaction history of the account.
- `transfer(ATM &receiver, int amount)`: Transfers a specified amount of money from the account to another account.

## Notes

- This program is for educational purposes and does not involve real banking operations.
- It uses the C++ standard library (`<bits/stdc++.h>`) for convenience in including common header files.

Feel free to explore and modify the program according to your needs!
