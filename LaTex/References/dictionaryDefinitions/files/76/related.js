(function() {
var related={"word":"orthography","lang":"en","related":["writing system"],"found":true};
if (related && related.found) {
	var link = "http://www.visualthesaurus.com/?word="+escape(related.word)+"&lang="+related.lang+"&ad=tdc.small";
	var internalLink = "http://www.thesaurus.com/browse/"+related.word+"#visualthesaurus";
	var title = "Click to explore &quot;orthography&quot; in the Visual Thesaurus.";
	document.write('<style>');
	document.write(' ._vtad { border-top: 1px solid #B6D0DD; padding: 15px 0 0 0; margin: 1em 0 0 0; background-image: url(http://syndication.visualthesaurus.com/ddc/gradient.png);background-repeat: repeat-x; background-position: 0 0; }');
	document.write(' ._vtad A { text-decoration: none; }  ._vtad A:hover { text-decoration: underline; }');	
	document.write(' ._vtad_flt { float: right;  margin: 0 0 10px 7px; } ._vtad_flt IMG { vertical-align: top; margin-bottom: 5px; border: 1px solid #CCCCCC;} ');
	document.write(' A._vtad_explore { letter-spacing: -.4px; font-family: verdana;display:block; line-height: 10px;  font-size: 11px;color: #0050BB; } ');
	document.write(' ._vtad_related { font-family: verdana; font-size: 12px; margin: 6px 0 6px; } ._vtad_related A { color: black; }');
	document.write(' ._vtad_header { font-family: georgia; line-height: 10px; font-size: 14px; color: #575757; } ._vtad_header IMG { vertical-align: top; margin-right: 7px; } ._vtad_header A { font-family: Times New Roman, serif; font-size: 14px; font-weight: bold; color: black; }');
	document.write(' A._vtad_other { font-family: verdana; font-size: 1em; color: #0050BB; }');	
	document.write('</style>');	
	document.write('<a name="visualthesaurus"></a><div class="_vtad" >');
		document.write('<div class="_vtad_flt"><a href="'+link+'" title="'+title+'" ><img src="http://syndication.visualthesaurus.com/ddc/small/'+_query+'.gif"></a><a class="_vtad_explore" href="'+link+'" class="theColor">Explore the Visual Thesaurus &#187;</a></div>');
		document.write('<div class="_vtad_header"><img src="http://syndication.visualthesaurus.com/ddc/new.png">Related Words for : <a href="'+internalLink+'" >'+_query+'</a></div>');
		document.write('<div class="_vtad_related">');
		for (var i=0;i<Math.min(5,related.related.length);i++) {
			if (i>0) document.write(", ");
			document.write('<a href="'+internalLink+'">'+related.related[i]+'</a>');
		}		
		document.write('</div>');
		document.write('<div><a class="_vtad_other" href="'+internalLink+'">View more related words &#187;</a></div>');
     	document.write('<br style="clear: right;"></div>');
}})();