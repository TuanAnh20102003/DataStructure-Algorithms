#include <stdio.h>
#include <stdlib.h>
#define min_distance 1
int itinerary[1000];
int cost_matrix[1000][1000];
int currentBus=0;
int min_cost=10000000;
int n,m;
int visited[100];
int destination[100];
int min_itinerary[100];
int current_cost = 0;
void init(){
    for(int i = 1; i <= 2*n;i++){
        visited[i]=0;
        destination[i+n]=0;
    }
}
int check_early_stop(int k){
	float x_cost = 0;
	for (int i = 0; i <= k-1 ; i++)
    {
	int city_i = itinerary[i];
	int next_city_i = itinerary[i+1];
	x_cost += cost_matrix[city_i][next_city_i];
	}
	if (x_cost + (2*n+1-k) * min_distance > min_cost){
		return 1;
	}
	return 0;
}
void update_solution(){
    current_cost = 0;
    for (int i = 0; i <= 2*n ; i++){
    	int city_i = itinerary[i];
    	int next_city_i = itinerary[i+1];
    	if(i<2*n){
        	current_cost += cost_matrix[city_i][next_city_i];
    	}
    	else{
        	current_cost +=cost_matrix[city_i][0];	
    	}
    }
    if (current_cost < min_cost){
        min_cost = current_cost;
        for(int i = 1; i <=2*n; i++){
			min_itinerary[i] = itinerary[i];
		}
	}
}
void print_final_solution(){
	for(int i = 1; i <=2*n ; i++){
		printf("%d ", min_itinerary[i]);
	}
}	

void thu (int k){
    if(currentBus==0){
        for(int v = 1;v<=n;v++){
            if(visited[v]==0){
                itinerary[k] = v;
                if (check_early_stop(k)){
                    continue;
                }
                visited[v]=1;
                destination[v+n]=1;
                currentBus++;
            	thu(k+1);
                visited[v]=0;
                destination[v+n]=0;
                currentBus--;
            }
        }
    }
    else if(currentBus==m){
        for(int v = 1+n; v<=2*n; v++){
            if(visited[v]==0 && destination[v] == 1){
                itinerary[k]=v;
                if (check_early_stop(k)){
                    continue;
                }
                visited[v]=1;
                destination[v]=0;
                currentBus--;
                if(k == 2*n){
                    update_solution();
                }
                else {
                	thu(k+1);
				}
                visited[v]=0;
                destination[v]=1;
                currentBus++;
            }
        }
    }
    else {
        for(int v = 1; v<=2*n; v++){
            if( visited[v] == 0 && v<=n){
                itinerary[k]=v;
                if (check_early_stop(k)){
                    continue;
                }
                visited[v]=1;
                destination[v+n]=1;
                currentBus++;
                thu(k+1);
                visited[v]=0;
                destination[v+n]=0;
                currentBus--;
            }
            if (visited[v] == 0 && destination[v] == 1){
                itinerary[k]=v;
                if (check_early_stop(k)){
                    continue;
                }
                visited[v]=1;
                destination[v]=0;
                currentBus--;
                
                if(k == 2*n){
                    update_solution();
                }
                else {
                	thu(k+1);
				}
                visited[v]=0;
                destination[v]=1;
                currentBus++;
            }
            
        }
    }
}
int main()
{
	init();
    itinerary[0]=0;
    scanf("%d",&n);
    scanf("%d",&m);
    for(int i = 0; i<=2*n; i++){
        for(int j =0; j<=2*n; j++){
            scanf("%d",&cost_matrix[i][j]);
        }
    }
    thu(1);
    printf("%d",min_cost);
   
}

