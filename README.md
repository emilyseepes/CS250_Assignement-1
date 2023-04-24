# **Video Game Prompt**
> The designers are experimenting with different maps, which consist of various elements *(characters, naimals, rocks, trees, etc.).* The various elements have been grouped in three seperate files **(fauna.txt , characters.txt and "structures.txt)**. The program allows the user to load elements and their attributes from provided files, and print them on the screen for closer inspection before experimenting witht the map.

## Three Files:

### **Fauna:**
+ ID *(integar)*: Identifies the element
+ Texture *(string)*: Specifies the appearance of the element 
+ Color *(string)*
+ Health *(double)*
+ Dimensions *(doubles)*: length, width, and height
+ Hostile *(boolean)*: dtermines if the animal is hostile (1) or peaceful (0)

### **Character:**
+ ID 
+ First Name
+ Last Name 
+ Health *(double)*
+ Dimensions *(doubles)*: length, width, and height

### **Structure:**
+ ID 
+ Texture
+ Dimensions *(doubles)*: length, width, and height

### **Dimension:**
+ Length
+ Width
+ Height 

## Key Tasks ##

### + Creating 4 Structs ###
### + Create 3 Arrays with the following types: ###
        >Fauna
        >Structure
        >Character
### + Calculate the average length, width, and height of all elements in each category ###
### + Create function **PrintHealthRange** that prompts user to insert a max and min value for character's health attribute. Proceed to print all chatacter's whose health falls in that range ###
### + Create Main Menu ###
