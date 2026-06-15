The most frequently found macro in Linux device drivers is BUG_ON/BUG and WARN_ON

BUG_ON(condition)

or

if (condition)
    BUG()

grep in the drivers folder for BUG_ON( gave 5000 plus count, and for WARN_ON gave more than 6000 count

What does BUG() macro do?

	Prints the contents of the registers

	Prints Stack Trace

	Current Process dies

What does WARN() macro do?

	Prints the contents of the registers

	Prints Stack Trace.

