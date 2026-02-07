#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <ctime>
#include <fstream>
#include <sstream>
#include <algorithm>
#include <windows.h>

const float MIN_BALANCE = 1000.0f;
const float PENALTY_FEE = 5.0f;

// --- Function Prototypes ---
std::string current_time_str();
void log_to_file(const std::string& message);
std::string format_money_indian(float amount);
void checkBalance(float balance);
float deposit(float balance, float amount);
float withdraw(float balance, float amount);

int main() {
    // --- STEP 1: ENABLE UTF-8 FOR RUPEE SYMBOL ---
    SetConsoleOutputCP(65001);
    // Note: If you see a '?' or box, change your Console Font to "Consolas" or "Lucida Console"
    // ---------------------------------------------

    int choice = 0;
    float balance = 0.0f;
    
    // Initial Log
    std::stringstream ss;
    ss << "[" << current_time_str() << "] *** System Started ***\n";
    log_to_file(ss.str());

    std::cout << "*** Welcome to the Banking System (Indian Format) ***\n";

    do {
        std::cout << "\nSelect an option:\n";
        std::cout << "1. Check Balance\n";
        std::cout << "2. Deposit\n";
        std::cout << "3. Withdraw\n";
        std::cout << "4. Exit\n";
        std::cout << "Enter your choice: ";

        if (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(10000, '\n');
            choice = 0;
        }

        float amount;
        switch (choice) {
            case 1:
                checkBalance(balance);
                break;
            case 2:
                std::cout << "Enter amount to deposit: ";
                std::cin >> amount;
                balance = deposit(balance, amount);
                break;
            case 3:
                std::cout << "Enter amount to withdraw: ";
                std::cin >> amount;
                balance = withdraw(balance, amount);
                break;
            case 4:
            {
                std::cout << "[" << current_time_str() << "] Exiting......\n";
                std::stringstream exitLog;
                exitLog << "[" << current_time_str() << "] System Exit.\n--------------------------\n";
                log_to_file(exitLog.str());
                Sleep(1000);
                std::cout << "Thank you for using the banking system. Goodbye!\n";
                break;
            }
            default:
                std::cout << "Invalid choice.\n";
        }
    } while (choice != 4);

    return 0;
}

// --- UPDATED: Now adds '₹' to the start ---
// Converts 1234567 -> "₹12,34,567.00"
std::string format_money_indian(float amount) {
    std::stringstream ss;
    ss << std::fixed << std::setprecision(2) << amount;
    std::string temp = ss.str();

    // Find decimal point
    size_t decimal_idx = temp.find('.');
    std::string decimalPart = temp.substr(decimal_idx);
    std::string intPart = temp.substr(0, decimal_idx);

    std::string result = "";
    int count = 0;
    bool firstGroupDone = false;

    // Iterate backwards through integer part
    for (int i = intPart.length() - 1; i >= 0; i--) {
        if (intPart[i] == '-') {
            result += '-';
            continue;
        }

        result += intPart[i];
        count++;

        if (i > 0 && intPart[i - 1] != '-') {
            if (!firstGroupDone) {
                if (count == 3) {
                    result += ',';
                    count = 0;
                    firstGroupDone = true;
                }
            }
            else {
                if (count == 2) {
                    result += ',';
                    count = 0;
                }
            }
        }
    }

    std::reverse(result.begin(), result.end());
    return "₹" + result + decimalPart;
}

void log_to_file(const std::string& message) {
    std::ofstream fp("banking-log.txt", std::ios::app);
    if (fp.is_open()) {
        fp << message;
        fp.close();
    }
}

void checkBalance(float balance) {
    std::string mBuf = format_money_indian(balance);

    std::cout << "[" << current_time_str() << "] Your current balance is:   " << mBuf << "\n";

    std::stringstream msg;
    msg << "[" << current_time_str() << "] ACTION: Check Balance | Balance: " << mBuf << "\n";
    log_to_file(msg.str());

    if (balance < 0) {
        std::cout << "Warning: Your account is overdrawn!\n";
    }
    else if (balance < MIN_BALANCE) {
        std::string minBuf = format_money_indian(MIN_BALANCE);
        std::cout << "Alert: Balance is below " << minBuf << ". Consider depositing funds.\n";
    }
}

float deposit(float balance, float amount) {
    if (amount < 0) {
        std::cout << "[" << current_time_str() << "] Invalid amount.\n";
        return balance;
    }

    balance += amount;

    std::string mAmt = format_money_indian(amount);
    std::string mBal = format_money_indian(balance);

    std::cout << "[" << current_time_str() << "] Deposited:   " << mAmt << "\n";
    std::cout << "New Balance: " << mBal << "\n";

    std::stringstream msg;
    msg << "[" << current_time_str() << "] ACTION: Deposit       | Amount: +" << mAmt << " | Balance: " << mBal << "\n";
    log_to_file(msg.str());

    return balance;
}

float withdraw(float balance, float amount) {
    if (amount < 0) {
        std::cout << "[" << current_time_str() << "] Invalid amount.\n";
        return balance;
    }

    if (amount > balance) {
        std::string mAmt = format_money_indian(amount);
        std::cout << "[" << current_time_str() << "] Insufficient funds.\n";

        std::stringstream msg;
        msg << "[" << current_time_str() << "] ERROR:  Withdraw Fail | Amount: -" << mAmt << " | Insufficient Funds\n";
        log_to_file(msg.str());
        return balance;
    }

    balance -= amount;

    std::string mAmt = format_money_indian(amount);
    std::string mBal = format_money_indian(balance);

    std::cout << "[" << current_time_str() << "] Successfully withdrew: " << mAmt << "\n";

    std::stringstream msg;
    msg << "[" << current_time_str() << "] ACTION: Withdraw      | Amount: -" << mAmt << " | Balance: " << mBal << "\n";
    log_to_file(msg.str());

    if (balance < MIN_BALANCE) {
        std::string mPen = format_money_indian(PENALTY_FEE);
        std::string mMin = format_money_indian(MIN_BALANCE);

        std::cout << "\n*** ALERT: Balance is below " << mMin << "! ***\n";
        std::cout << "*** Applying penalty charge of " << mPen << " ***\n";

        balance -= PENALTY_FEE;
        mBal = format_money_indian(balance);

        std::stringstream feeMsg;
        feeMsg << "[" << current_time_str() << "] SYSTEM: PENALTY FEE   | Amount: -" << mPen << " | Reason: Low Balance (<" << mMin << ")\n";
        log_to_file(feeMsg.str());

        std::cout << "New Balance after penalty: " << mBal << "\n\n";
    }

    return balance;
}

std::string current_time_str() {
    time_t t = time(NULL);
    struct tm *tm_info = localtime(&t);
    
    char buf[64];
    if (tm_info) {
        strftime(buf, sizeof(buf), "%I:%M:%S %p", tm_info);
    } else {
        return "unknown";
    }
    return std::string(buf);
}