class Solution():
	def merge_iter(self, list1, list2):
		currItem = None
		curr     = None
		root     = None
		while True:
			if(list1 == None):
				currItem = list2
			elif(list2 == None):
				currItem = list1
			elif(list1.val < list2.val):
				currItem = list1
			else:
				currItem = list2

			if(currItem == None): break

			if(currItem == list1):
				list1 = list1.next if list1 else None
			elif(currItem == list2):
				list2 = list2.next if list2 else None

			if(root == None):
				root = currItem
				curr = currItem
			else:
				curr.next = currItem
				curr = curr.next
		
		return root

	def merge_help_rec(self, list1_beg, list2_beg, prev_l1, list1, prev_l2, list2):
		if(list1 == None):
			prev_l1.next = list2_beg
			return list1_beg
		elif(list2 == None):
			prev_l2.next = list1_beg
			return list2_beg
		elif(list1.val < list2.val):
			prev_l1 = list1
			list1 = list1.next
			prev_l1.next = list2
			list2_beg = prev_l1
			return merge_help_rec(self, list1_beg, list2_beg,prev_l1,list1,prev_l2,list2)
		else:  //list2.val <= list2.val
			prev_l2 = list2
			list2 = list2.next
			prev_l2.next = list1
			list1_beg = prev_l2
			return merge_help_rec(self, list1_beg, list2_beg,prev_l1,list1,prev_l2,list2)
			
	def merge_rec(self, list1, list2):
		if(list1 == None):
			return list2
		elif(list2 == None):
			return list1
		else:
			list1_beg = list1
			list2_beg = list2
			return merge_help_rec(self, list1_beg, list2_beg, None, list1, None, list2)
		

class LinkedNode(object):
	def __init__(self, value):
		self.val   = value
		self.next  = None

def make_linked_list(input_lst):
	root = None
	curr = None
	for i in range(0, len(input_lst)):
		if(i == 0):
			root = LinkedNode(input_lst[i])
			curr = root
		else:
			curr.next = LinkedNode(input_lst[i])
			curr = curr.next
	return root

def print_ll(input_lst):
	print('[',end='')
	while(input_lst != None):
		print(input_lst.val, end=' ')
		input_lst = input_lst.next
	print(']',end='')
	print("\n")

list1 = make_linked_list([4,5,6,9,100])
list2 = make_linked_list([7,10,101])

merged = Solution().merge_iter(list1,list2)

print_ll(merged)
