
# Minitalk

Minitalk is a **42 school project** that explores **inter-process communication (IPC)** using **UNIX signals**. The goal is to create a simple message exchange system between a **server** and a **client** using `SIGUSR1` and `SIGUSR2`.

---

## 🛠 **Features**
- The **server** can receive messages from multiple clients.
- The **client** sends a string to the server, one bit at a time.
- The **server** reconstructs and prints the received message.
- Handles message acknowledgment.
- Detects when a new client starts sending a message.

---

## 📌 **Usage**

### **1️⃣ Compile the project**
Run the following command to compile both the server and client:
```sh
make
```
This generates two executables:
- `./server`
- `./client`

And for the bonus part, run the following command to compile both the server_bonus and client_bonus:
```sh
make bonus
```
This generates two executables:
- `./server_bonus`
- `./client_bonus`

### **2️⃣ Start the server**
Run the server to get its PID (Process ID):
```sh
./server
```
Output example:
```
PID -> 12345
Waiting for a message...
```

### **3️⃣ Send a message from the client**
In a separate terminal, use the client to send a message:
```sh
./client <server_pid> "Hello, world!"
```
Example:
```sh
./client 12345 "Hello from Minitalk!"
```

### **4️⃣ Server output**
Once the message is received, the server prints:
```
Hello from Minitalk!
```

---

## ⚙ **Implementation Details**
- Uses `SIGUSR1` and `SIGUSR2` to transmit **bits** of each character.
- The **client** sends one bit at a time using `kill()`.
- The **server** reconstructs characters and prints them.
- Detects a **new client** and resets if necessary.
- After processing the received signal, the server sends a signal back to the client. (bonus part)

---

## 🧹 **Cleaning up**
To remove compiled binaries:
```sh
make fclean
```

---

## 📝 **Notes**
- The message transmission **speed** is controlled using `usleep()` to prevent overwhelming the server.
- The **server must be running** before sending messages.
- The project follows the **42 Norm** (restricted functions and style guide).

---

## 🚀 **Bonus Features**
✅ Message acknowledgment
✅ Unicode character support

---

## 📜 **License**
This project is part of **42 School's curriculum** and is subject to their academic policies.

---

## 🤝 **Contributing**
Feel free to **fork** this repository and submit a **pull request** if you have improvements!

---

## 📬 **Contact**
For any questions, feel free to reach out to me!

Happy coding! 🚀



