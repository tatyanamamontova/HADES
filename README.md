# HADES
## Scripts connected with HADES experiment
1. Directory «treeMaker»
  1.1. Directory «lists» contains lists of trees in Hades format (HTree).
  1.2. Directory «scripts»:
    1.2.1. env.sh runs the install of root and HYDRA environment
    1.2.2. make.sh runs «make» for the source code makeTree.cc
    1.2.3. submitJobs.sh runs jobs which convert trees.
    1.2.4. jobScript.sh is used to display what happens when we run submitJobs.sh
  1.3. Directory «src»
    1.3.1. makeTree.cc is used to convert trees; 
    1.3.2. MHConstants.h contains different constants and enumerators
    1.3.3. mhqvector.h - class for Qn vectors
    1.3.4. mhwalldivider.h - divides FW in rings
2. Directory «macros» contains scripts for a drawing distribution of different variables 
3. Directory «results» contains figures that were obtained with the scripts from the directory «macros» 
