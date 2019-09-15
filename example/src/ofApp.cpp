#include "ofApp.h"

#include "ofxZip.h"

namespace 
{
	bool verifyCheck( vector< unsigned char > & src0, vector< unsigned char > & src1 )
	{
		if ( src0.size() != src1.size() ) return false;
		
		int n = src0.size();
		for ( int i=0; i<n; ++i )
		{
			if ( src0.at(i) != src1.at(i) )
			{
				return false;
			}
		}
		
		return true;
	}
	
}

//--------------------------------------------------------------
void ofApp::setup() {
	
	/// test
	{
		size_t a;

	}
	
	/// original data
	vector< unsigned char > src;
	for ( int i=0; i<10000; ++i )
	{
		src.push_back( i%256 );
	}
	
	/// compress test
	{
		/// compress
		vector< unsigned char > result = ofxZip::compress( src );
		
		/// uncompress
		vector< unsigned char > uncompressed = ofxZip::uncompress( result );
		
		bool verified = verifyCheck( src, uncompressed );
		
		cout << "src.size(): " << src.size() << endl;
		cout << "result.size(): " << result.size() << endl;
		cout << "uncompressed.size(): " << uncompressed.size() << endl;
		
		if ( verified ) cout << "** verified! **" << endl;
		
		cout << endl;
	
	}
	
	/// ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
	/// compress test with level
	for ( int level=1; level<=9; ++level )
	{
		/// compress
		vector< unsigned char > result = ofxZip::compress( src, level );
		
		/// uncompress
		vector< unsigned char > uncompressed = ofxZip::uncompress( result );
		
		bool verified = verifyCheck( src, uncompressed );
		
		cout << "level: " << level << endl;
		cout << "src.size(): " << src.size() << endl;
		cout << "result.size(): " << result.size() << endl;
		cout << "uncompressed.size(): " << uncompressed.size() << endl;
		
		if ( verified ) cout << "** verified! **" << endl;
		
		cout << endl;
	}	
	
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) { 

}
