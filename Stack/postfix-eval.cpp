/******************************************************************************

Welcome to GDB Online.
GDB online is an online compiler and debugger tool for C, C++, Python, Java, PHP, Ruby, Perl,
C#, OCaml, VB, Swift, Pascal, Fortran, Haskell, Objective-C, Assembly, HTML, CSS, JS, SQLite, Prolog.
Code, Compile, Run and Debug online from anywhere in world.

*******************************************************************************/
#include <iostream>
#include<cstring>

using namespace std;
class Stack{
    public:
    int top;
    int size;
    int* S;
    Stack(int n){
        top = -1;
        size = n;
        S = new int[size];
    }
};


void push(Stack* st, int x){
    if(st->top==st->size-1){
        cout<<"stack overflow"<<endl;
    }
    else{
        st->top++;
        st->S[st->top] = x;
    }
}

int pop(Stack* st){
    char x = -1;
    if(st->top==-1){
        cout<<"stack is underflow"<<endl;
    }
    else{
        x = st->S[st->top];
        st->top--;
    }
    return x;
}

int isEmpty(Stack st){
    if(st.top==-1) return 1;
    else return 0;
}

int isFull(Stack st){
    if(st.top==st.size-1) return 1;
    else return 0;
}

int stackTop(Stack st){
    int x=-1;
    if(st.top==-1){
        return -1;
    }
    else{
        x = st.S[st.top];
    }
    return x;
}

int isOperand(char x){
    if(x=='+' || x=='-' || x=='*' || x=='/')
    return 0;
    else
    return 1;
}

int precedence(char x){
    if(x=='+' || x=='-') return 1;
    else if(x=='*' || x=='/') return 2;
    return 0;
}

char* postFix(Stack* st, char* infix){
    char* pfix = new char[strlen(infix)+1];
    int i=0,j=0;
    
    while(infix[i]!='\0'){
        if(isOperand(infix[i])){
            pfix[j++]=infix[i++];
        }
        else{
            if(precedence(infix[i])>precedence(stackTop(*st))){
                push(st,infix[i++]);
            }
            else{
                pfix[j++]=pop(st);
            }
        }
    }
    
    while(!isEmpty(*st)){
        pfix[j++] = pop(st);
    }
    return pfix;
}

int evalPostFix(Stack* st,char* infix){
    int i,x1,x2,r;
    for (i = 0; infix[i]!='\0'; i++) {
        
        if(isOperand(infix[i])){
            push(st,infix[i]-'0');
        }
        else{
            x2 = pop(st);
            x1 = pop(st);
            
            switch(infix[i]){
                case '+': r = x2+x1; push(st,r); break;
                case '-': r = x2-x1; push(st,r); break;
                case '*': r = x2*x1; push(st,r); break;
                case '/': r = x2/x1; push(st,r); break;
            }
        }
        /* code */
    }
    
    return pop(st);
}

int main()
{
    cout<<"Hello World"<<endl;
    
    //char infix[] = "a+b*c-d/e";
    
    char infix[] = "6+5+3*4";
    
    
    Stack st(strlen(infix));
    
    cout<<st.size<<endl;
    
    cout<<postFix(&st,infix)<<endl;
    cout<<evalPostFix(&st,postFix(&st,infix))<<endl;
    return 0;
}