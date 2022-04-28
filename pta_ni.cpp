#include<iostream>
#include<algorithm>
#include<vector>
#include<cstring>

using namespace std;

struct process{
	int no;
	int burst;
	int wait;
	int arrival;
	int turn_around;
	int priority;
};

bool cmp(process p1,process p2){
	if (p1.arrival==p2.arrival){
	if (p1.priority==p2.priority){
	return p1.no<p2.no;
	}
	return p1.priority<p2.priority;
	}
	return p1.arrival<p2.arrival;
}

bool cmp1(process p1,process p2){
	return p1.arrival<p2.arrival;
}
bool cmp2(process p1,process p2){
	return p1.no<p2.no;
}
void PS(process*, int);
void RRS(process*,int);
void print_gantt_chart(vector<process>, int);
void print_table(vector<process>,int);

int main(){
	for(int j=0;j<2;j++){
	int n;
	cout<<"\nEnter total number of processes: ";
	cin>>n;
	process p[n];
	for (int i=0;i<n;i++){
	p[i].no=i+1;
	cout<<i+1<<" process details: \n";
	if(j==0)
	cout<<"Enter arrival time, burst time and priority: ";
	else
	cout<<"Enter arrival time and burst time: ";
	cin>>p[i].arrival;
	cin>>p[i].burst;
	if(j==0)
	cin>>p[i].priority;
	p[i].wait=0;
	p[i].turn_around=0;
	}
	if (j==0)
	PS(p,n);
	else
	RRS(p,n);
	}
}

void PS(process p[],int n){
	vector<process> temp;
	process temp1;
	cout<<"\n\t\tPriority Scheduling\n\t\t*******************";
	for(int i=0;i<n;i++){
	temp1.no=p[i].no;
	temp1.arrival=p[i].arrival;
	temp1.wait=p[i].wait;
	temp1.burst=p[i].burst;
	temp1.turn_around=p[i].turn_around;
	temp1.priority=p[i].priority;
	temp.push_back(temp1);
	}
	sort(temp.begin(),temp.end(),cmp);
	vector<process> op;
	for(int i=0;i<n;i++){
	op.push_back(temp[i]);
	}
	for(int i=0;i<n;i++){
	if (i!=0){
	op[i].wait=op[i-1].turn_around-op[i].arrival+op[i-1].arrival;
	op[i].turn_around=op[i].wait+op[i].burst;
	}
	else{
	op[i].turn_around=op[i].burst;
	}
	}
	int sum_waiting_time = 0, sum_turnaround_time=0;
	for(int i=0; i<n; i++) {
 sum_waiting_time += op[i].wait;
 sum_turnaround_time += op[i].turn_around;
 }
 cout<<endl;
 print_table(op,n);
 printf("Total Waiting Time : %-2d\n", sum_waiting_time);
 printf("Average Waiting Time : %-2.2lf\n", (double)sum_waiting_time / (double) n);
 printf("Total Turnaround Time : %-2d\n", sum_turnaround_time);
 printf("Average Turnaround Time : %-2.2lf\n", (double)sum_turnaround_time / (double) n);
	print_gantt_chart(op,n);
}

void RRS(process p[],int n){
	int tq,total=0;
	cout<<"Enter quantum time: ";
	cin>>tq;
	process temp[n];
	cout<<"\n\t\tRound Robin Scheduling\n\t\t**********************\n";
	for(int i=0;i<n;i++){
	temp[i].no=p[i].no;
	temp[i].arrival=p[i].arrival;
	temp[i].wait=p[i].wait;
	temp[i].burst=p[i].burst;
	temp[i].turn_around=p[i].turn_around;
	total+=(temp[i].burst/tq);
	if (temp[i].burst%tq!=0){
	total++;
	}
	}
	sort(temp,temp+n,cmp1);
	vector<process> op;
	vector<process> op1(2*total);
	for(int i=0;i<n;i++){
	op1[i]=temp[i];
	}
	int k=n;
	vector<process>::iterator it;
	for (int i=0;i<total;i++){
	process x,y;
	y=op1[i];
	x=op1[i];
	if (y.burst<=tq){
	x.burst=y.burst;
	}
	else{
	x.burst=tq;
	y.burst-=tq;
	op1[k]=y;
	k++;
	}
	op.push_back(x);
	}
	
	for(int i=0;i<total;i++){
	if (i!=0){
	op[i].wait=op[i-1].turn_around-op[i].arrival+op[i-1].arrival;
	op[i].turn_around=op[i].wait+op[i].burst;
	}
	else{
	op[i].turn_around=op[i].burst;
	}
	}
	int turn[n];
	memset(turn,0,sizeof turn);
	for(int i=0;i<total;i++){
	p[op[i].no-1].wait+=(op[i].wait-turn[op[i].no-1]);
	turn[op[i].no-1]=op[i].turn_around;
	}
	vector<process> op2;
 for(int i=0;i<n;i++){
 p[i].turn_around+=(p[i].wait+p[i].burst);
 op2.push_back(p[i]);
	}
	int sum_waiting_time = 0, sum_turnaround_time=0;
	for(int i=0; i<n ;i++) {
 sum_waiting_time += p[i].wait;
 sum_turnaround_time += p[i].turn_around;
 }
 cout<<endl;
	print_table(op2,n);
 printf("Total Waiting Time : %-2d\n", sum_waiting_time);
 printf("Average Waiting Time : %-2.2lf\n", (double)sum_waiting_time / (double) n);
 printf("Total Turnaround Time : %-2d\n", sum_turnaround_time);
 printf("Average Turnaround Time : %-2.2lf\n", (double)sum_turnaround_time / (double) n);
	print_gantt_chart(op,total);
}

void print_table(vector<process> p, int n){
	sort(p.begin(),p.end(),cmp2);
 int i;
 cout<<"+-----+--------------+------------+--------------+-----------------+\n";
 cout<<"| PID | Arrival Time | Burst Time | Waiting Time | Turnaround Time |\n";
 cout<<"+-----+--------------+------------+--------------+-----------------+\n";

 for(i=0; i<n; i++) {
 printf("| %2d | %2d | %2d | %2d | %2d |\n", p[i].no, p[i].arrival,p[i].burst, p[i].wait, p[i].turn_around);
 cout<<"+-----+--------------+------------+--------------+-----------------+\n";
 }
 cout<<"\n\n";
}

void print_gantt_chart(vector<process> p, int n){
	cout<<"\n GANTT CHART \n *********** \n";
 int i, j;
 printf("+");
 for(i=0; i<n; i++) {
 for(j=0; j<p[i].burst; j++) printf("--");
 printf("+");
 }
 printf("\n|");
 for(i=0; i<n; i++) {
 for(j=0; j<p[i].burst - 1; j++) printf(" ");
 printf("P%d", p[i].no);
 for(j=0; j<p[i].burst - 1; j++) printf(" ");
 printf("|");
 }
 printf("\n+");
 for(i=0; i<n; i++) {
 for(j=0; j<p[i].burst; j++) printf("--");
 printf("+");
 }
 printf("\n0");
 for(i=0; i<n; i++) {
 for(j=0; j<p[i].burst; j++) printf(" ");
 if(p[i].turn_around+p[i].arrival > 9) printf("\b");
 printf("%d", p[i].turn_around+p[i].arrival);
 }
 printf("\n");
} 