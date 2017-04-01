The subdirectory ballstk contains the solution files 
for the ball & stick model.
nrngui init.hoc
will bring up the ball and stick model with a user interface.
The CellBuilder is in ballstk.ses

The subdirectory stemcell contains the solution files 
for the Continuous Create ("Managing Models on the Fly") 
part of this exercise.
stemcell.ses is the session file for the CellBuilder, 
with compartmentalization governed by d_lambda = 0.1.
start.ses contains a user interface for exercising this model.
nrngui init.hoc
will start the standard GUI, load the CellBuilder (which 
was saved with Continuous Create ON so loading it will 
automatically create the model cell), and set up the 
user interface.
