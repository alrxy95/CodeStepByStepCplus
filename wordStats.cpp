void wordStats( string filename ) {
    
    ifstream input( filename );
    string line;
    
    size_t totalNumOfWords = 0;  //size of object in bytes
    double totalLenOfWords = 0;
    
    string token;
    char charInWord;
    map< char, int > charFreq;  //map <key value, mapped value>
    map< char, int >::iterator iter;
    
    cout << endl;
    
    //if file can't be opened
    if ( !input.is_open() ) {
        cout << "Error, bad input file" << endl;
        
        
    } else {
        
        while ( true ) {
            input >> token;
            if( input ) {
                totalNumOfWords++;
                totalLenOfWords += token.length();
                
                for( size_t i = 0; i < token.length(); i++ ) {
                    if ( isalpha( token[ i ] ) ) {
                        charInWord =  token[ i ];
                        charInWord = toupper( charInWord );
                        charFreq[ charInWord  ]++;
                    } //end if()
                } //end for()
            } else {
                break;
            }
        } // end while()
        input.close();
        cout << setw( 14 ) << left << "Total words" << " = " << totalNumOfWords << endl;
        cout << setw( 10 ) << left <<  "Average length" << " = " << ( totalLenOfWords / totalNumOfWords ) << endl;
        cout << setw( 13 ) << left << "Unique letters" << " = " << charFreq.size() << endl;
        
    }
}








