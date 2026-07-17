class Solution {
public:
    int largestRectangleArea(vector<int>& arr) {
        vector<int>left;
       stack<pair<int , int>>s;
       int n=arr.size();
       int pseudoindex = -1;
    //   long long i;
     
       for(int i=0; i<n; i++)
       {
           if(s.size()==0)             //if stack is empty
               left.push_back(pseudoindex);
           else if( s.size()>0 && s.top().first<arr[i])
               left.push_back(s.top().second);
           else if(s.size()>0 && s.top().first>=arr[i])
           {
               while(s.size()>0 && s.top().first>=arr[i])
                   s.pop();
               
               if(s.size()==0)
                   left.push_back(pseudoindex);
               else
                   left.push_back(s.top().second);
           }
           s.push({arr[i],i});
       }
       
    //   while(!s.empty())
    //       s.pop();
           
       //NSR
       
       vector<int>right;
       stack<pair<int, int>>s1;
        pseudoindex = n;
       
       for( int i=n-1; i>=0; i--)
       {
           if(s1.size()==0)             //if stack is empty
               right.push_back(pseudoindex);
           else if( s1.size()>0 && s1.top().first<arr[i])
               right.push_back(s1.top().second);
           else if(s1.size()>0 && s1.top().first>=arr[i])
           {
               while(s1.size()>0 && s1.top().first>=arr[i])
                   s1.pop();
               
               if(s1.size()==0)
                   right.push_back(pseudoindex);
               else
                   right.push_back(s1.top().second);
           }
           s1.push({arr[i],i});
       }
       reverse(right.begin(),right.end());
       
       
       //obtaining area by calculating width
       
       // dont use extra vectors to calculate width, memory overflows  
       
        for(int i=0;i<n;i++)
          right[i] = right[i]-left[i]-1;
          
          for( int i=0;i<n;i++){
              right[i] = arr[i]*right[i];
          }
        int max=right[0];
        for(int i=0;i<n;i++)
            
                if(right[i]>max)
                max = right[i];
            
        return max;
    }
};
