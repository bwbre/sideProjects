# sideProjects
Will contain various side projects, usually for practice and learning.

MAPGENERATOR: 
    currently experimenting with cell automata simulation. idea is to modify it and most likely combine it with other procgen methods like i saw from some videos online. ultimately i want to see if i can randomize the cell's behaviour and movement to randomly generate a map. 
        --possible approach: have the cell(s?) carve out paths in the grids and create walls when/if it changes directions.
            --modify or simplify the paths carved out so paths are cleaner.
            --figure out how to ensure pathing is random and that it ideally doesnt go over prev paths (for now)






BANKING SYSTEM:
Design a banking system that simulates basic banking operations such as account creation, deposits, withdrawals, and balance inquiries.

---BASIC OVERVIEW---
Bank parent class
    customer subclass
    employee subclass

main menu for customer
    -Greet and header
    -Balance Inquiry
    -Profile
        -customer->personalinfo
    -Account info
        -accounts
            *may have multiple*
        -transaction history
            *filters?*
        -balance
            *which accounts?*
        -services(?)
            *not sure if it should be nested here?*
        -Back/Main Menu
    -Account services
        -deposit
            *which accounts, what source?*
        -withdraw
            *which accounts, cash/check/what?*
        -transfer
            *To whom/from who? how much, what accounts?*
        -balance
            *which accounts?*
        -back/main menu
    -EXIT
    
end

