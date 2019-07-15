
Follow these steps to make a New large root file

1. Change file paths in the change_file_name.C

2. Run the make_new_root.sh in the same directory as the *_analyzed.root files, DBinput2_to_root.C, and change_file_name.C


3. Merge all the new *_update_analyzed.root files with this command in terminal
    $ hadd Big.root *_update_analyzed.root

4. Then change file paths in the merge_ttrees_test3.C, then run this from the same directory as Big.root & merge_ttrees_test3.C
    $ root -l merge_ttrees_test3.C

    ...let finish...

    $ root -l change_file_name2.C

5. The final file "NewBig.root" will now be in the directory.
