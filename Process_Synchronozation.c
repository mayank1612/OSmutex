#include<stdio.h>
#include<unistd.h>
#include<pthread.h>




int items[4][3] = {0};
//last row indicated wheteher the student completed the assignment 
// where 0 indicates not completed and 1 means completed
pthread_mutex_t lk;
void *stu1(){
    pthread_mutex_lock(&lk);
    printf("\nStudent 1 is having Pen only.");
    printf("\nStudent1 took Paper and Question Paper.\n");
    items[3][0] = 1;
    printf("Student1 is finished with the assisgnment.\n");
    pthread_mutex_unlock(&lk);
}

void *stu2(){
    pthread_mutex_lock(&lk);
    printf("\nStudent 2is having Paper only.");
    printf("\nStudent2 took Pen and Question Paper.\n");
    items[3][1] = 1;
    printf("Student2 is finished with the assisgnment.\n");
    pthread_mutex_unlock(&lk);
}

void *stu3(){
    pthread_mutex_lock(&lk);
    printf("\nStudent3 is having Question paper only.");
    printf("\nStudent3 took Pen and Paper.\n");
    //as by default he had pen
    items[3][2] = 1;
    printf("Student3 is finished with the assisgnment.\n");
    pthread_mutex_unlock(&lk);
}

int option1, option2;

void *teacher()
{
	pthread_mutex_lock(&lk);
	printf("\nResource 1 to be kept on table: ");
	scanf("%d",&option1);  
	printf("\nResource 2 to be kept on table: ");
	scanf("%d",&option2);
	pthread_mutex_unlock(&lk);
}


int main(){
    pthread_mutex_init(&lk, NULL);
    
    pthread_t student_thread;
    pthread_t teacher_thread;

    printf("\nAllocations(what each number means)\n\n");
    printf("\t1 = Pen\n\t2 = Paper\n\t3 = Question Paper\n");
    
    items[0][0] = 1; //student1 has pen
    items[1][1] = 2; //student2 has paper
    items[2][2] = 3; //student3 has question_paper
    
 

    while(1)
{
        //to check whether student has already done the assignment or not
        if(items[3][0] && items[3][1] && items[3][2])
	{
            break;
	}
        
        
        pthread_create(&teacher_thread, NULL, teacher, NULL);
        pthread_join(teacher_thread, NULL);

        if(((option1 == 2 && option2 == 3) ||(option1 == 3 && option2 == 2)) && items[3][0] == 0){
            pthread_create(&student_thread, NULL, stu1, NULL);
            pthread_join(student_thread, NULL);
        }
        else if(((option1 == 1 && option2 == 3) ||(option1 == 3 && option2 == 1)) && items[3][1] == 0){
            pthread_create(&student_thread, NULL, stu2, NULL);
            pthread_join(student_thread, NULL);
        }
        else if(((option1 == 1 && option2 == 2) ||(option1 == 2 && option2 == 1)) && items[3][2] == 0){
            pthread_create(&student_thread, NULL, stu3, NULL);
            pthread_join(student_thread, NULL);
        }
        else{
            printf("\nEither particular student is done with their assisgnment or you have given wrong inputs!\n");
        }
}

printf("Its time to exit!..");
   
}
