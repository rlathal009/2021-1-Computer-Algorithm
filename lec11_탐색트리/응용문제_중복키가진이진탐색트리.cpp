//#include <stdio.h>
//#include <stdlib.h>
//
//typedef struct TreeNode {
//	int key;
//	struct TreeNode* parent, *left, *right;
//}TreeNode;
//
//typedef struct
//{
//	TreeNode* root;
//}TreeType;
//
//void initTree(TreeType* T)
//{
//	T->root = (TreeNode*)malloc(sizeof(TreeNode));
//	T->root->parent = T->root->left = T->root->right = NULL;
//}
//
//int isExternal(TreeNode* w)
//{
//	return(w->left == NULL && w->right == NULL);
//}
//
//void expandExternal(TreeNode* w)
//{
//	TreeNode* l = (TreeNode*)malloc(sizeof(TreeNode));
//	TreeNode* r = (TreeNode*)malloc(sizeof(TreeNode));
//	l->left = NULL;
//	l->right = NULL;
//	l->parent = w;
//	r->left = NULL;
//	r->right = NULL;
//	r->parent = w;
//	w->left = l;
//	w->right = r;
//}
//
//TreeNode* treeSearch(TreeNode* v, int k)
//{
//	if (isExternal(v))
//		return v;
//	if (k == v->key)
//		return v;
//	else if (k < v->key)
//		return treeSearch(v->left, k);
//	else
//		return treeSearch(v->right, k);
//}
//
//int findElement(TreeType* T, int k)
//{
//	TreeNode* w = treeSearch(T->root, k);
//
//	if (isExternal(w))
//		return 0;
//	else
//		return w->key;
//}
//
//void insertItem(TreeType* T, int k)
//{
//	TreeNode* w = treeSearch(T->root, k);
//	while (!isExternal(w)) //inInternal ����ؼ� ���
//		w = treeSearch(w->right, k);
//	w->key = k;  //�ߺ��� Ű ���� ����
//	expandExternal(w);
//}
//
//TreeNode* sibling(TreeNode* z)
//{
//	if (z->parent->left == z)
//		return z->parent->right;
//	else
//		return z->parent->left;
//}
//
//TreeNode* reduceExternal(TreeType* T, TreeNode* z)
//{
//	TreeNode* w = z->parent;
//	TreeNode* g = w->parent;
//	TreeNode* zs = sibling(z);
//	zs->parent = g;
//
//	if (g == NULL)
//		T->root = zs;
//	else
//	{
//		if (w == g->left) //�����Ǵ� ��尡 �θ����� ���������� �������� Ȯ��
//			g->left = zs;
//		else
//			g->right = zs;
//	}
//	free(z);
//	free(w);
//	return zs;
//}
//
//TreeNode* inOrderSucc(TreeNode* w)
//{
//	w = w->right;
//	while (w->left != NULL)
//		w = w->left;
//	return w;
//}
//
//void findAllElements(TreeType* T, int k)
//{
//	int count = 0;
//	TreeNode* w = treeSearch(T->root, k);
//
//	while (!isExternal(w))
//	{
//		count++;
//		w = treeSearch(w->right, k);
//	}
//	printf("%d���� %d���� �����մϴ�. \n", count, k);
//}
//
//int removeElement(TreeType* T, int k)
//{
//	TreeNode* w = treeSearch(T->root, k);
//
//	if (isExternal(w))
//		return 0;
//
//	TreeNode* z, *y;
//	z = w->left;
//	if (!isExternal(z))
//		z = w->right;
//	if (isExternal(z))
//		reduceExternal(T, z);
//	else
//	{
//		z = inOrderSucc(w); //��������� ã�� �Լ�
//		y = z->parent;
//		w->key = y->key;
//		reduceExternal(T, z);
//	}
//	return k;
//}
//
//void removeAllElement(TreeType* T, int k)
//{
//	TreeNode* w, *z, *y;
//
//	while (!isExternal(w))
//	{
//		z = w->left;
//		if (!isExternal(z))
//			z = w->right;
//		if (isExternal(z))
//			reduceExternal(T, z);
//		else
//		{
//			z = inOrderSucc(w); //��������� ã�� �Լ�
//			y = z->parent;
//			w->key = y->key;
//			reduceExternal(T, z);
//		}
//		w = treeSearch(T->root, k);
//	}
//	
//	
//}
//
//void preOrder(TreeNode* root)
//{
//	if (isExternal(root))  //�̺κ��� ������ ��������� ����ִ� ���� ���� ��µż� �����Ⱚ�� �Բ���µ�.
//		return;
//	printf("[%d] ", root->key);
//	preOrder(root->left);
//	preOrder(root->right);
//}
//
//int main()
//{
//	TreeType* T = (TreeType*)malloc(sizeof(TreeType));
//	initTree(T);
//
//	insertItem(T, 39);
//	insertItem(T, 24);
//	insertItem(T, 55);
//	insertItem(T, 41);
//	insertItem(T, 8);
//	insertItem(T, 33);
//	insertItem(T, 30);
//	insertItem(T, 24);
//	insertItem(T, 27);
//	insertItem(T, 33);
//	insertItem(T, 24);
//	insertItem(T, 24);
//
//	preOrder(T->root); printf("\n");
//	getchar();
//
//	findAllElements(T, 24);
//}