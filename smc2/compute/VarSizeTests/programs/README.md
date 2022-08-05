
# Optimal Variable Size Notes

- Addition: Size increments by 1
- Multiplication: Size doubles 
- Shift: increment by shift size
- Array: if different ops at different indices, take max
- Branches: take max possible of both branches
- Loops: 
   - bounded: evaluate based on ops
   - unbounded: give 'normal' type size
- Functions: 
   - evaluate to obtain a function based on the sizes of the parameters
   - assign size based on plugging in sizes of arguments
   
   
# DSL implementation features 

Necessary:

- size annotations for declarations

Consider: 

- resize operation for allowing size guarantees at a specific program point
- loop bound annotation to enable analysis during loops


# Program Types:

### Realistic Programs: 

- `real-world` directory

These are real-world programs that can benefit from optimal variable sizes.

### Simple Functionality Tests:  

Directories: 
 
- `addition`
- `multiplication`
- `increment`
- `shift` (TODO)

These tests are designed to test the functionality of finding optimal variable sizes with simple operations.
Variable sizes will increase during these operations. 

### Control Functionality Tests:

Directories:

- `control`

These tests are designed to ensure operations that are not intended to increase variable size are not doing so.
Variable sizes should be identical to those given for the input. 

### Syntax Functionality Tests:

Directories:

- `loops`
- `branches` 
- `arrays`
- `combined-simple`

These tests are designed to tests further elements of syntax with the variable sizing operations. 
`combined-simple` combines a variety of operations to ensure correct sizing.

### Complex Functionality Tests:

- `functions` (TODO)
- `combined-ops` (TODO)

These programs are more complex/have more complex operations in order to test out the functionality with further syntax. 









