struct _node{
	ll x,y,max,value,height;
	bool color;
	struct _node *left,*right;
	_node(ll _x,ll _y,ll _max, ll _val,ll _hei){
		x=_x;y=_y;max=_max;value=_val,height=_hei;
		left=right=NULL;
	}
};

class IntervalTree{
private:
	typedef struct _node node;
	node *_root;

	ll height(node *root){
		if(root==NULL)
			return 0;
		return root->height;
	}
	ll getBalance(node *root){
		if(root==NULL){
			return 0;
		}
		return height(root->left)-height(root->right);
	}
	void updateMax(node *x){
		ll L=(x->left==NULL)?0:x->left->max;
		ll R=(x->right==NULL)?0:x->right->max;
		x->max=max(x->y,max(L,R));
	}
	node* rightRotate(node *y){
		node *x = y->left;
		node *t2 = x->right;
		x->right=y;
		y->left=t2;
		y->height=max(height(x->left),height(x->right))+1;
		x->height=max(height(y->left),height(y->right))+1;
		updateMax(y);
		updateMax(x);
		return x;
	}
	node* leftRotate(node *x){
		node *y=x->right;
		node *t2= y->left;
		y->left=x;

		x->right=t2;
		x->height=max(height(x->left),height(x->right))+1;
		y->height=max(height(y->left),height(y->right))+1;
		updateMax(x);
		updateMax(y);
		return y;
	}
	bool doOverlap(_node*root,ll _x,ll _y){
	if(_x<=root->x && _y>=root->y)		//es mas grande y lo contiene
		return 1;
	if(_x>root->x && _x<root->y)		//se sobrepone por la derecha
		return 1;
 	if(_y>root->x && _y<root->y)		//se sobrepone por la izquierda
		return 1;
	return 0;
	}
	node* minValueNode(node *root){
		while(root->left!=NULL)
			root=root->left;
		return root;
	}
	node* insert(node *root,ll _x,ll _y,ll _val,ll _h){
		if(root==NULL){
			return new node(_x,_y,_y,_val,_h);
		}
		root->max=max(_y,root->max);	//actualizo indice mas grande
		if(_x < root->x){
			root->left=insert(root->left,_x,_y,_val,_h+1);
		}else{
			root->right=insert(root->right,_x,_y,_val,_h+1);
		}
		root->height=1+max(height(root->left),height(root->right));
		ll balance=getBalance(root);
		if(balance>1 &&_x<root->left->x){	// LL
			return rightRotate(root);
		}		
		if(balance<-1 &&_x>root->right->x){	// RR
			return leftRotate(root);
		}
		if(balance>1 && _x > root->left->x){ // LR
			root->left=leftRotate(root->left);
			return rightRotate(root);
		}
		if(balance<-1 && _x<root->right->x){
			root->right=rightRotate(root->right);
			return leftRotate(root);
		}
		return root;
	}
	ll countOverlapping(ll _x, ll _y, node *root){
		if(root==NULL) return 0;
		ll res=0;
		if(doOverlap(root,_x,_y)) res++;	//cambiar si se suma valor
		return res+countOverlapping(_x,_y,root->left)+countOverlapping(_x,_y,root->right);
	}
public:
	IntervalTree(){
		_root=NULL;
	}
	void insert(ll _x,ll _y,ll _v=1){
		_root=insert(_root,_x,_y,_v,0);

	}
	ll countOverlapping(ll _x, ll _y){
		return countOverlapping(_x,_y,_root);
	}
};