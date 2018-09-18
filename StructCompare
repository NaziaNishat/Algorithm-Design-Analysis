#include<bits/stdc++.h>
using namespace std;

struct Node{
    int key;

    Node(int a)
    {
        key = a;
    }
};

struct compare{
   bool operator()(Node a, Node b)
   {
     return a.key > b.key;
   }
};

int main()
{
  Node a = Node(7);
  Node b = Node(3);
  Node c = Node(10);

  priority_queue<Node, vector<Node> , compare >pq;
  pq.push(a);
  pq.push(b);
  pq.push(c);

  while(!pq.empty())
  {
      Node temp = pq.top();
      pq.pop();
      cout<<temp.key<<" ";
  }

  cout<<endl;

}
