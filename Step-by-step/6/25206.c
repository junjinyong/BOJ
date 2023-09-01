#include <stdio.h>

int main() {
    char grade[3];
    double credit, total_credit = 0, total_grade = 0;
    
    for(int i = 0; i < 20; ++i) {
        scanf("%*s %lf %s", &credit, grade);
        
        if(grade[0] != 'P') {
            total_credit = total_credit + credit;
            
            if(grade[0] != 'F') {
                double score = ('E' - grade[0]) + (grade[1] == '+' ? 0.5 : 0.0);
                total_grade = total_grade + credit * score;
            }
        }
    }
    
    printf("%.15lf\n", total_grade / total_credit);
    
    return 0;
}
