
bool binarySearch(std::vector<int> v, int minIndex, int maxIndex, int itemSearch)
{
		if(minIndex > maxIndex){
			return false;		
		}
		
		middleIndex = maxIndex + minIndex / 2;

		if(v.at(middleIndex) == itemSearch){
			return true;
		}
		else {
			if (v.at(middleIndex) > itemSearch) {
				binarySearch(v, minIndex, middleIndex - 1, itemSearch);
			} else {
				binarySearch(v, middleIndex + 1, maxIndex, itemSearch);			
			}			
		}
		
}