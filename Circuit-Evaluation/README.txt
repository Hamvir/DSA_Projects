///////////////////////////////////////////  CIRCUIT EVALUATION  //////////////////////////////////////

This contains code to read an input file containing data regarding gates, their inputs and types and finding their outputs.

///////////////// INPUT FORMAT ///////////////

The input should be a text file and it should be present in the same folder where "main_file.cpp" is present.

Following things are to be followed for input text formats:

-> Lines beginning with "#" are ignored.
-> Dont leave any lines as gap between 2 lines.
-> 1st 3 lines should contain single integers defining the values of N(number of nets), E(number of gates) and P(number of outputs).
-> Next E lines contain name, types and input-output of gates.
-> Give a space between each variable (ex - U0 NAND2 1 2 3) .
-> Dont give space after the last variable(in above example 3 is the last variable, so no space after it) .
-> Next P lines give the input nets and their present value separated by a space.
-> Name the input text file as "input_data.txt".
-> Refer to the sample "input_data.txt" given in the folder.

////////////////// OUTPUT FORMAT //////////////

All net values are printed in a text file. There will be N lines.
Each line containing nets and their value separated by a space (ex- 4 1).
The output text file will be created and saved in the same location as "main_file.cpp".

///////////////// CODE //////////////////

Code bascically has 3 parts.

PART - 1 : It reads the value from input text data and stores it in appropriate variables for further processing.
PART - 2 : It calculates the output of gates from given inputs by considering their types and properties.
PART - 3 : It stores the output values calculated in part 2 in a text file and also prints it in running time.

///////////////// FUNCTIONS AND STRUCTURES PRESENT //////////////

gate: It is a structure that stores the structure of gate, that is their name, type, inputs and output.

stoi:
input - a string variable
output/return type - a integer
use - converts string variable to integer variable.

This function may not be used as in most cases its a built-in function.

find_output:
input - gate type structure, array pointer to "Net" array storing input/output variables, size of Net array
output - void
use - calculates output from inputs and type of gate.

main: input text file is read and outputs calculated and output text file is created.  

/////////////////// COMPILING AND RUNNING ///////////////////////

Can use any IDE to compile and run the program.
-> Download the repo.
-> Create your "own input_data.txt" file in the same folder where "main_file.cpp" is present( or copy it from sample_inputs_outputs folder). 
-> Check the input formats to avoid errors.
-> open the main_file.cpp in any cpp IDE(preferred g++) and compile it and then run it.
-> The output file will be generated and saved in the current folder in the name "output.txt".
-> Your IDE may not recognise "bits/stdc++" header used in that case comment it and uncomment all the rest headers commented.
