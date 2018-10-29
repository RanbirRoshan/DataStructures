


int SearchAppHeapNode::GetKeyOffset()
{
	return offsetof(SearchAppHeapNode, vFrequency);
}

std::string* SearchAppHeapNode::GetKeyword()
{
	return vKeyWord;
}

int SearchAppHeapNode::GetFrequency()
{
	return vFrequency;
}