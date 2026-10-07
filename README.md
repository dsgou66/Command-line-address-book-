Contacts

A command-line contacts program written in C, supporting create, read, update, and delete operations.

Features

· Add a contact (name, phone, email)
· Delete a contact (by ID)
· Update a contact (by ID)
· Search for a contact (by ID or name)
· Display all contacts

Build

Requires gcc and make:

```bash
make
```

Run

```bash
./contacts
```

Or:

```bash
make run
```

Clean build artifacts

```bash
make clean
```

Project structure

```
contacts/
├── main.c        # Main program, menu interaction
├── contact.h     # Interface declarations (types + functions)
├── contact.c     # Implementation (CRUD + dynamic resizing)
├── Makefile      # Build script
└── README.md     # This document
```

Usage

After running, enter a number as prompted by the menu to select an operation:

```
=====Contacts=====
1. Display all
2. Search for a contact
3. Add a contact
4. Update a contact
5. Delete a contact
0. Exit
```

· When adding a contact, enter the name, phone, and email in order
· When searching, you can choose to search by ID or name
· When updating, you need to enter the ID to update and all the new information

Author

dsgou66

License

MIT License

Thanks see
