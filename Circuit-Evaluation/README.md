# CIRCUIT EVALUATION

Digital circuits are composed of “gates” such as NOT, AND, OR, NAND, XOR etc. Each such gate has well defined Boolean functionality. A combinational circuit consists of multiple gates connected to each other, along with several “primary inputs” and “primary outputs”.The figure "image.png" shows an example of such a combinational circuit. Each “net” is either a primary input, or the output of a gate, and all the nets are numbered. The gates are given identifiers such as U0, U1 etc. and each gate has a specific type (NOT, AND2, NAND3 etc.).

Along with this circuit,the present state of the primary inputs are also given.
The goal is to print out the values that will be obtained at each net in the circuit after evaluating the given circuit. The following are assumed:
>The nets are numbered from 1 to N (N being the total number of nets in the circuit).

>Gates are given unique identifiers such as U0, U1 etc. (these could be strings in general)

>The possible types of gates are: NOT, AND2, OR2, NAND2, NOR2, XOR2, XNOR2, NAND3 and NOR3. For example, in the above circuit: U1 is of type XNOR2 (2-input XNOR gate), while U2 is of type NOR3 (3-input NOR gate).

Refer to readme.txt for further running the code and how to use it.
