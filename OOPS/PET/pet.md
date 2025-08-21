# CORE COMPONENTS

1. Pet Class
    - Attributes (private) : name, hunger, happiness, energy
    - Methods (public) : 
        - feed(), play(), sleep(), 
        - showStatus(), 
        - tick() → decrease stats over time, 
        - isAlive() → checks if pet is alive.
    
2. Main Game Loop 
    - Display pet status
    - Ask users for action
    - Call the corresponding method
    - Update stats with tick()
    - Loop pets until pets die    


# What the Project Actually Does

1. Simulates a digital pet that has hunger, energy, happiness levels.
2. The player interacts by feeding, playing, or letting the pet sleep.
3. The pet’s stats naturally decrease over time (tick).
4. The game continues until the pet dies (any stat reaches 0).
5. Gives you hands-on OOP practice: encapsulation, methods, constructors.