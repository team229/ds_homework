/*
 * @Descripttion: 
 * @version: 1.0
 * @Author: Gypsophlia
 * @Date: 2020-11-25 22:27:03
 * @LastEditTime: 2020-11-26 14:27:10
 */
#include<iostream>
#include<algorithm>
#include<map>
#include<string>
#include<vector>
#include<queue>
using namespace std;

typedef struct HuffmanTree
{
    int flag;
    string s;
    int fre;
    struct HuffmanTree *ld,*rd;
    HuffmanTree(int a,string b,int c){
        flag=a;
        s=b;
        fre=c;
    }
};

typedef pair<string,int> PAIR;
bool Cmpbyfre(PAIR lhs,PAIR rhs){
    return lhs.second > rhs.second;
};
struct cmpfre{
    bool operator () (node* x,node* y){
        return x->fre > y->fre;
    }
};

class Solution
{
    private:
        HuffmanTree *root;
        string str;
        map<string, int> fres;
        priority_queue<node*, vector<node*>, cmpfre> nodes;
    public:
        Solution(string s){
            str=s;

        }
        void calu_fre(){
            string byte;
            for(int i=0;i<4;i++){
                byte.assign(str,i*8,8);    
                if(fres.count(byte))
                    fres[byte]+=1;
                else{
                    fres[byte]=1;
                }
            }
        }
        void sort_map(){
            vector<PAIR> fres_vec(fres.begin(),fres.end()); 
            sort(fres_vec.begin(),fres_vec.end(),Cmpbyfre);
            for(int i=0;i!=fres_vec.size();i++){
                HuffmanTree *node=new HuffmanTree(1,fres_vec[i].first,fres_vec[i].second);
                nodes.push(node);
            }
            /* test:
            while(!nodes.empty()){
                cout<<nodes.top()->s<<endl;
                nodes.pop();
            }
            */
        }

        void create_huffman(){
            HuffmanTree *temp,*node1,*node2;
            while(nodes.size()>1){
                node1=nodes.top();
                nodes.pop();
                node2=nodes.top();
                nodes.pop();
                temp=new HuffmanTree(0,node1->fre+node2->fre);
                temp->ld=node1;
                temp->rd=node2;
                if(!node.empty())
                    nodes.push(temp);
            }
            root=temp;
        }

        void coding_tree(){
            
        }
};  

int main(){
    string s;
    s="00000000000000010101010101010101";
    Solution *slu=new Solution(s);
    slu->calu_fre();
    slu->sort_map();
}