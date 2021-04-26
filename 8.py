def merge(left_list,right_list):
	i,j = 0,0
	res = []
	while i<len(left_list) and j<len(right_list):
		if left_list[i] <= right_list[j]:
			res.append(left_list[i])
			i += 1
		else:
			res.append(right_list[j])
			j += 1
	res += left_list[i:]
	res += right_list[j:]
	return res

def mergesort(in_list):
	if len(in_list) <= 1:
		return in_list
	else:
		mid = int(len(in_list)/2)
		left_list = mergesort(in_list[ :mid])
		right_list = mergesort(in_list[mid: ])
		return merge(left_list,right_list)

num_list = [6,2,9,3,1,10,15,32,23,287,198,54,7]
print("The original list is: ")
print(num_list)

print("The Sorted List is: ")
print (mergesort(num_list))
