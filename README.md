# 📦 HailOS  

<p align="center">
  <img src="https://img.shields.io/badge/OS-Experimental-blue?style=for-the-badge"/>
  <img src="https://img.shields.io/badge/Architecture-x86%20(32--bit)-orange?style=for-the-badge"/>
  <img src="https://img.shields.io/badge/Language-C%20%26%20Assembly-green?style=for-the-badge"/>
  <img src="https://img.shields.io/badge/Stage-Bootable%20Kernel-red?style=for-the-badge"/>
</p>

<p align="center">
  <img src="https://img.shields.io/github/stars/suyashgupta1109/hailOS?style=social" />
  <img src="https://img.shields.io/github/forks/suyashgupta1109/hailOS?style=social" />
</p>

---

## ✨ Overview  

**hailOS** is a **minimalistic operating system** built completely from scratch using **C** and **x86 Assembly**.  
It’s designed as a **learning-first project** to explore **low-level system programming, OS internals, and kernel design**.  

🚀 Current Features:
- Multiboot-compliant bootloader (GRUB)
- Basic kernel written in C
- Text-mode terminal with scrolling, colors, and cursor movement
- Simple shell with commands:  
  - `help` → list available commands  
  - `clear` → clear the screen  
  - `color <0–15>` → change text color  
- Keyboard input handling via PS/2 controller

---

## 🖥️ Demo Preview  

<p align="center">
  <img src="https://i.imgur.com/v8p3h86.png" width="600" alt="hailOS Boot Screen"/>
</p>  

*(Bootscreen with ASCII logo + shell prompt `> _`)*  

---

## 📂 Project Structure  

```bash
hailOS/
│── boot.s          # Multiboot-compliant bootloader (entry point)
│── kernel.c        # Main kernel: shell, commands, drivers
│── terminal.c/h    # Terminal: text rendering, colors, scrolling, cursor
│── keyboard.c/h    # PS/2 keyboard handler
│── io.h            # Low-level I/O port access
│── linker.ld       # Linker script for kernel memory layout
│── grub.cfg        # GRUB boot configuration
│── myos.bin        # Compiled kernel binary
│── myos.iso        # Bootable ISO image
│── README.md       # Project documentation
```

---

## ⚙️ Build & Run  

### 🔨 Prerequisites  
- **Cross Compiler**: `i686-elf-gcc` and `i686-elf-ld`  
- **GRUB** + **xorriso** (to build bootable ISO)  
- **QEMU** or **VirtualBox** (to run the OS)  

### 🏗️ Build Steps  
```bash
# 1. Compile bootloader + kernel
i686-elf-as boot.s -o boot.o
i686-elf-gcc -c kernel.c -o kernel.o -std=gnu99 -ffreestanding -O2 -Wall -Wextra

# 2. Link objects into kernel binary
i686-elf-ld -T linker.ld -o myos.bin boot.o kernel.o

# 3. Create ISO with GRUB
mkdir -p isodir/boot/grub
cp myos.bin isodir/boot/
echo 'set timeout=0
set default=0
menuentry "hailOS" {
    multiboot /boot/myos.bin
}' > isodir/boot/grub/grub.cfg
grub-mkrescue -o myos.iso isodir
```

### ▶️ Run in QEMU  
```bash
qemu-system-i386 -cdrom myos.iso
```

---

## 📜 Features in Action  

### 🎨 Terminal  
- Text rendering in VGA text mode  
- Supports: newlines, backspace, scrolling, cursor updates  

### ⌨️ Keyboard  
- Reads **scancodes** from PS/2 controller  
- Converts to ASCII and prints on terminal  

### 🐚 Shell  
- Minimal shell interface  
- Commands: `help`, `clear`, `color <id>`  

---

## 🧩 Roadmap  

- [ ] Add interrupt descriptor table (IDT) & IRQ handling  
- [ ] Paging & memory management  
- [ ] File system (basic FAT/exFAT)  
- [ ] User programs & multitasking  
- [ ] Graphical mode driver (VGA/Framebuffers)  

---

## 🙌 Contributors  

- **SOHAIL KHAN** (creator & maintainer)  

- *SUYASH GUPTA* (tester)

---

## 📚 References  

- [OSDev Wiki](https://wiki.osdev.org)  
- [Bran’s Kernel Development](https://www.osdever.net/bkerndev/Docs/basickernel.htm)  
- [JamesM’s Kernel Development](http://www.jamesmolloy.co.uk/tutorial_html/)  

---

## 📜 License  

This project is **for educational purposes only**.  
Feel free to fork, learn, and experiment 🚀  
