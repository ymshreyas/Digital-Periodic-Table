# Digital-Periodic-Table
## Introduction
The digital periodic table is an interactive tool that allows users to explore the properties of all known chemical elements. It is essentially a digital version of the traditional periodic table of elements, which is a tabular arrangement of the chemical elements based on their atomic structure and chemical properties. The digital periodic table typically includes information such as the element's atomic number, symbol, name, electron configuration, physical and chemical properties, as well as images and videos of the element and its applications. Digital periodic tables can be used for a variety of purposes, such as education, research, and industry. They are particularly useful for students and educators who want to learn more about the elements and their properties, as well as for scientists and engineers who need to quickly access information about specific elements for their work. Some digital periodic tables also include features such as quizzes and interactive games to help users learn about the elements in a fun and engaging way    

## Problem Statement
This Project aims at developing a digital periodic table that will help users in receiving information about different kind of elements, be it the S-block, P- block, D-block or F-block elements by ensuring that the information provided is accurate and complete.

## Description
There are 118 known elements in the periodic table. Hence to make operations performed on it, easy this tool named DIGITAL PERIODIC TABLE can be used. The code for this tool is done using c++. The different parts of the code are prepared by different algorithms. The logic of all functions will be reported.
The different parts /functions in the code are:
1) User input validation
2) Function for printing The Periodic Table
3) Data by atomic number
4) Data by element name
5) Data by symbol
6) Formatting the text
7) Body of the code
8) Function for continuing or quitting the loop.



## Loading the data into double xircular linked list
The data structure used in circular double linker list made up of small nodes containing individual spaces for parameters of any element along with pointers named next and previous for storing the address of next and previous linking elements. The globally declared pointers are Start, Cur(Current) and temp. The algorithm for the process of loading is as follows:

Step 1: Create a loop which traverses the file pointer till the EOF.

Step 2: Initially Start is set to NULL and hence the parameters are loaded into the node.

Step 3: Further till the EOF the parameters in individual files are copied into a node and simultaneously the nodes are linked.

Step 4: At the last when the loading of 118 elements are done the last and the first node are interlinked thus making it circular Double linked list.


![image](https://user-images.githubusercontent.com/123388366/233036902-617ab3d9-9c7a-4325-afea-6719a7c9997a.png)
###### Representation of data storage in double circular linked list

![image](https://user-images.githubusercontent.com/123388366/233037194-00f18fcc-75cb-4ec7-8815-388e3858ff97.png)
###### Creation of double circular linked list by coding


## Conclusion and Future scope
### Conclusion
The digital periodic table is a valuable tool for students to understand the properties and relationships between different elements. Here are some of the key conclusions that can be drawn from the digital periodic table:
1) The elements are organized into periods and groups based on their electron configurations, which determines their chemical properties.
2) The periodic table shows the trend of the elements' properties, such as atomic number, electronic configuration, element name, atomic number, atomic mass, state of    the lement and symbol of the element.
3) The noble gases have a stable electron configuration and are unreactive, while the alkali metals have a single valence electron and are highly reactive.
4) The program consists of many functions such as searching by element name, symbols and by atomic numbers.
5) We have also used file management to display all the characteristics of a particular element.
6) The data of all the elements are linked in a sequential manner using double circular linked list to reduce the ambiguity while searching for an element.

### Future Scope
1) To create a GUI for the digital periodic table for easier accessibility and handling.
2) Integrate the digital periodic table with online platforms such as social media, email, or mobile apps. This will allow users to access the system from anywhere and    anytime, making it more convenient for them to access the details of an element within no time.



## References
### Web references
[1] https://www.geeksforgeeks.org/periodic-table-of-elements/

[2] https://www.codewithc.com/modern-periodic-table-c-project/

[3] https://stackoverflow.com/questions/982388/how-to-implement-a-linked-list-in-c

[4] https://en.wikipedia.org/wiki/Periodic_table


### Text Books referred

[1] Data Structures Using C, Reema Thareja, 1st Edition, 2011, Oxford Higher Education

[2] Y. Langasm, M. J. Augenstein, A. M. Tenenbaum (2001) Data Structures Using C and C++
