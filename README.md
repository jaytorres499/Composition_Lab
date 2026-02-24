
## Data Dictionary

| Attribute      | Data Type     | Description                    |
|--------------- |---------------|--------------------------------|
| `accountNumber`| `std::string` | The bank accounts number.      |
| `accountName`  | `std::string` | The bank account holder name.  |
| `balance`      | `double`      | The bank account's balance.    |

## Methods List

| Method Signature                    | Return Type   | Description                              |
|-------------------------------------|---------------|------------------------------------------|
| `BankAccount()`                     | (Constructor) | Default constructor.                     |
| `BankAccount(name, number, money)`  | (Constructor) | Parameterized constructor.               |
| `BankAccount(other)` | (Constructor) | Copy constructor. |
| `BankAccount& operator=(other)` | (Operator) | Copy assignment operator. |
| `~BankAccount()` | (Deconstructor) | Deconstructor. |
| `SetName(name)`                     | `void`       | Changes the selected accounts name.      |
| `GetName()`                         | `std::string` | Returns the selected account's name.      |
| `GetNumber()`                       | `std::string` | Returns the selected account's number.   |
| `GetBalance()`                      | `double`      | Returns the selected account's balance.  |
| `+=(amount)`  | `Class Value`        | Adds to account balance by amount and returns modified balance value.       |
| `-=(amount)`  | `Class Value`        | Subtracts from account balance by amount and returns modified balance value.       |
| `==(other)` | `Bool` | Compares current object accountNumber to other's accountNumber and returns true or false. |
| `<(other)` | `Bool` | Compares current object balance to other's balance and returns true or false (Left side less than right side). |
| `>(other)` | `Bool` | Compares current object balance to other's balance and returns true or false (Left side more than right side). |
