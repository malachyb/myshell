/*
 * /I/We declare  that  this  material,  which  I/We now  submit for  assessment, is  entirely  my/our own work and has not been
 * taken from the work of others, save and to the extent that such work  has  been  cited  and  acknowledged  within  the  text
 * of my/our work.  I/We understand that  plagiarism,  collusion,  and  copying  are  grave  and  serious  offences  in the
 * university  and accept  the  penalties  that  would  be  imposed  should  I  engage  in  plagiarism,  collusion  or copying.
 * I/We have read and understood the Assignment Regulations. I/We have identified and  included  the  source  of  all  facts,
 * ideas,  opinions,  and  viewpoints  of  others  in  the assignment  references.  Direct  quotations  from  books,  journal
 * articles,  internet  sources, module  text,  or  any  other  source  whatsoever  are  acknowledged  and  the  source  cited
 * are identified  in  the  assignment  references.  This  assignment,  or  any  part  of  it,  has  not  been previously
 * submitted  by  me/us or  any  other  person  for  assessment  on  this  or  any  other course of study.
 *
 * I/We have read and understood the referencing guidelines found at http://www.dcu.ie/info/regulations/plagiarism.shtml,
 * https://www4.dcu.ie/students/az/plagiarismand/or recommended in the assignment guidelines.
 *
 * Name: Malachy Byrne
 * Student Number: 19463716
*/

#include <stdio.h>
#include <dirent.h>

char* file_code(int code) {
    char* dir_code = "\033[32m";
    char* file_code = "\033[37m";
    if (code == 4)
        return dir_code;
    return file_code;
}

int main(int argc, char* argv[]) {
    char* dir_loc = ".";
    struct dirent *curr_dir;
    if (argc > 1)
        dir_loc = argv[1];
    DIR *directory = opendir(dir_loc);
    if(directory) {
        while((curr_dir = readdir(directory)) != NULL)
            printf("%s%s\n", file_code(curr_dir->d_type), curr_dir->d_name);
    }
    return 0;
}
