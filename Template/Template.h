template<class T>
struct ListNode
{
	T data;
	ListNode * next;
};

/************************************************************************/
/* Reverse a list                                                       */
/************************************************************************/
template<class T>
ListNode<T> * ReverseList(ListNode<T> * head)
{
	ListNode<T> * pre = NULL;
	ListNode<T> * cur = head;
	ListNode<T> * nxt = cur ? cur->next : NULL;

	while (cur)
	{
		cur->next = pre;
		pre = cur;
		cur = nxt;
		nxt = nxt ? nxt->next : NULL;

		if (cur == NULL)
		{
			return pre;
		}
	}
	return cur;
}