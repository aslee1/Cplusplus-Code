
#include <string>
#include "..\Include\StringParserClass.h"
#include "..\Include\FileReader.h"
#include "..\Include\constants.h"
#include "..\Include\Debug_Help.h"

using namespace std;
using namespace KP_StringParserClass;
 
		char	*pStartTag;
		char	*pEndTag;
		bool	areTagsSet=false;
		int		lastError=0;
		StringParserClass::StringParserClass(void){

		}
		StringParserClass::~StringParserClass(void){

		}
		/*indicates the last error the library experienced
		resets error on completion, indicates a global variable that holds
		error state*/
		int StringParserClass::getLastError(){
			return lastError;
		}



		/*these are the start tag and the end tags that we want to find,
		presumably the data of interest is between them
		points to the data or to the "tags" aka points into the string or points to "<to>"???*/
		bool StringParserClass::setTags(const char *pStartTagr, const char *pEndTagr){

			if(pStartTagr ==0||pEndTagr==0||pStartTagr =='\0'||pEndTagr=='\0'){
				lastError=ERROR_TAGS_NULL;
				return false;
			}
			
			areTagsSet=true;
			pStartTag=const_cast<char*>(pStartTagr);
			pEndTag=const_cast<char*>(pEndTagr);
			
			lastError=SUCCEEDED;
			return areTagsSet;
		}
		//going to search thru pDataToSearchThru, looking for info bracketed by
		//pStartTag and pEndTag, will add that data to myStrings
		bool StringParserClass::getDataBetweenTags(char *pDataToSearchThru, vector<string> &myVector){
			//I'm assuming we are just passed the string here
			bool start=false;
			string words="";
			bool tagfound=false;
			bool endtag=false;
			int endpointcount=0;
			 
			pStartTag++; 
			int startpointcount=0;
			char *copypData=pDataToSearchThru;
			if(areTagsSet){ //check to see if we have tags
				while(*pDataToSearchThru!='\0'){
					endtag=false; 
					if(*pDataToSearchThru=='<'){
						//search for tags by opening tag character, in this case '<'
						tagfound=true; 
					}
					if(tagfound){
						//we've found a tag, so let's make sure it's a real one
						pDataToSearchThru++; 
						while(*pStartTag==*pDataToSearchThru){
							if(*pStartTag=='>'){
								//will only set start=true if we get through the whole tag without breaking, i.e. is a
								//real tag
								start=true;
							}
							pStartTag++;
							startpointcount++;
							pDataToSearchThru++;
						}
					}
					while(start&&*pDataToSearchThru!='\0'){
							//We've found a real tag, so let's capture the data
							words+=*pDataToSearchThru;
							pDataToSearchThru++; 
						
						if(*pDataToSearchThru=='<'){
							//if we hit another tag within the first tag, make sure we don't exit the first tag until we
							//hit the first tag's close tag mark ('>')
							copypData=pDataToSearchThru;
							while(*copypData==*pEndTag&&*copypData!='\0'){
								if(*pEndTag=='>'){
									endtag=true; 
									
								}
								copypData++;
								pEndTag++;
								endpointcount++;
								
							}
						}
						if(endtag){
							//we have found the endtag, add the words we found to our main vector and reset the start boolean
							myVector.push_back(words);
							start=false;
						}
						else{
							/*we have not found the endtag we're looking for
							//decrement endtags we have to watch out for by the endtags we've found
							since we may have many lesser subtags open and close within one capture-worthy tag*/
							pEndTag=pEndTag-endpointcount;
							endpointcount=0;
						}
					}
					//reset variables for end of loop
					tagfound=false;
					pStartTag=pStartTag-startpointcount;
					startpointcount=0;
					pEndTag=pEndTag-endpointcount;
					endpointcount=0;
					words="";
					if(!start&&!endtag){
						pDataToSearchThru++; 
						tagfound=false;
					}
				}
			}
			//end of method cleanup of errors
			else{
				lastError=ERROR_TAGS_NULL;
			}
			lastError=SUCCEEDED;
			return start;
		}
		void StringParserClass::cleanup(){

			delete pStartTag;
			delete pEndTag;

		}
		//pStart points to where we want to search in array
		//locate tags. we do not know where they are but we know what they are.
		bool StringParserClass::findTag(char *pTagToLookFor, char *&pStart, char *&pEnd){
			while(*pStart!=*pTagToLookFor){//This will find the first instance of '<'
				pStart++;
				if(*pStart=='\0'){
					return false;
				}
			}
			pEnd=pStart; 
			while(*pEnd!='>'){//This only finds the next instance of '>' with no checks.
				pEnd++;
				if(*pEnd=='\0'){
					return false;
				}
			}
			if(pStart==0&&pEnd==0){
				return false;
			}
			//setTags(pStart,pEnd);
			return true;
		}