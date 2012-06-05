(function() {
var _UDS_CONST_LOCALE = 'en';
var _UDS_CONST_SHORT_DATE_PATTERN = 'MDY';
var _UDS_MSG_SEARCHER_IMAGE = ('Image');
var _UDS_MSG_SEARCHER_WEB = ('Web');
var _UDS_MSG_SEARCHER_BLOG = ('Blog');
var _UDS_MSG_SEARCHER_VIDEO = ('Video');
var _UDS_MSG_SEARCHER_LOCAL = ('Local');
var _UDS_MSG_SEARCHCONTROL_SAVE = ('save');
var _UDS_MSG_SEARCHCONTROL_KEEP = ('keep');
var _UDS_MSG_SEARCHCONTROL_INCLUDE = ('include');
var _UDS_MSG_SEARCHCONTROL_COPY = ('copy');
var _UDS_MSG_SEARCHCONTROL_CLOSE = ('close');
var _UDS_MSG_SEARCHCONTROL_SPONSORED_LINKS = ('Sponsored Links');
var _UDS_MSG_SEARCHCONTROL_SEE_MORE = ('see more...');
var _UDS_MSG_SEARCHCONTROL_WATERMARK = ('clipped from Google');
var _UDS_MSG_SEARCHER_CONFIG_SET_LOCATION = ('Search location');
var _UDS_MSG_SEARCHER_CONFIG_DISABLE_ADDRESS_LOOKUP = ('Disable address lookup');
var _UDS_MSG_SEARCHER_NEWS = ('News');
function _UDS_MSG_MINUTES_AGO(AGE_MINUTES_AGO) {return ('' + AGE_MINUTES_AGO + ' minutes ago');}
var _UDS_MSG_ONE_HOUR_AGO = ('1 hour ago');
function _UDS_MSG_HOURS_AGO(AGE_HOURS_AGO) {return ('' + AGE_HOURS_AGO + ' hours ago');}
function _UDS_MSG_NEWS_ALL_N_RELATED(NUMBER) {return ('all ' + NUMBER + ' related');}
var _UDS_MSG_NEWS_RELATED = ('Related Articles');
var _UDS_MSG_BRANDING_STRING = ('powered by Google');
var _UDS_MSG_SORT_BY_DATE = ('Sort by date');
var _UDS_MSG_MONTH_ABBR_JAN = ('Jan');
var _UDS_MSG_MONTH_ABBR_FEB = ('Feb');
var _UDS_MSG_MONTH_ABBR_MAR = ('Mar');
var _UDS_MSG_MONTH_ABBR_APR = ('Apr');
var _UDS_MSG_MONTH_ABBR_MAY = ('May');
var _UDS_MSG_MONTH_ABBR_JUN = ('Jun');
var _UDS_MSG_MONTH_ABBR_JUL = ('Jul');
var _UDS_MSG_MONTH_ABBR_AUG = ('Aug');
var _UDS_MSG_MONTH_ABBR_SEP = ('Sep');
var _UDS_MSG_MONTH_ABBR_OCT = ('Oct');
var _UDS_MSG_MONTH_ABBR_NOV = ('Nov');
var _UDS_MSG_MONTH_ABBR_DEC = ('Dec');
var _UDS_MSG_DIRECTIONS = ('directions');
var _UDS_MSG_CLEAR_RESULTS = ('clear results');
var _UDS_MSG_SHOW_ONE_RESULT = ('show one result');
var _UDS_MSG_SHOW_MORE_RESULTS = ('show more results');
var _UDS_MSG_SHOW_ALL_RESULTS = ('show all results');
var _UDS_MSG_SETTINGS = ('settings');
var _UDS_MSG_SEARCH = ('search');
var _UDS_MSG_SEARCH_UC = ('Search');
var _UDS_MSG_POWERED_BY = ('powered by');
function _UDS_MSG_LOCAL_ATTRIBUTION(LOCAL_RESULTS_PROVIDER) {return ('Business listings provided by ' + LOCAL_RESULTS_PROVIDER + '');}
var _UDS_MSG_SEARCHER_BOOK = ('Book');
function _UDS_MSG_FOUND_ON_PAGE(FOUND_ON_PAGE) {return ('Page ' + FOUND_ON_PAGE + '');}
function _UDS_MSG_TOTAL_PAGE_COUNT(PAGE_COUNT) {return ('' + PAGE_COUNT + ' pages');}
var _UDS_MSG_SEARCHER_BY = ('by');
var _UDS_MSG_SEARCHER_CODE = ('Code');
var _UDS_MSG_UNKNOWN_LICENSE = ('Unknown License');
var _UDS_MSG_SEARCHER_GSA = ('Search Appliance');
var _UDS_MSG_SEARCHCONTROL_MORERESULTS = ('More results');
var _UDS_MSG_SEARCHCONTROL_PREVIOUS = ('Previous');
var _UDS_MSG_SEARCHCONTROL_NEXT = ('Next');
var _UDS_MSG_GET_DIRECTIONS = ('Get directions');
var _UDS_MSG_GET_DIRECTIONS_TO_HERE = ('To here');
var _UDS_MSG_GET_DIRECTIONS_FROM_HERE = ('From here');
var _UDS_MSG_CLEAR_RESULTS_UC = ('Clear results');
var _UDS_MSG_SEARCH_THE_MAP = ('search the map');
var _UDS_MSG_SCROLL_THROUGH_RESULTS = ('scroll through results');
var _UDS_MSG_EDIT_TAGS = ('edit tags');
var _UDS_MSG_TAG_THIS_SEARCH = ('tag this search');
var _UDS_MSG_SEARCH_STRING = ('search string');
var _UDS_MSG_OPTIONAL_LABEL = ('optional label');
var _UDS_MSG_DELETE = ('delete');
var _UDS_MSG_DELETED = ('deleted');
var _UDS_MSG_CANCEL = ('cancel');
var _UDS_MSG_UPLOAD_YOUR_VIDEOS = ('upload your own video');
var _UDS_MSG_IM_DONE_WATCHING = ('i\047m done watching this');
var _UDS_MSG_CLOSE_VIDEO_PLAYER = ('close video player');
var _UDS_MSG_NO_RESULTS = ('No Results');
var _UDS_MSG_LINKEDCSE_ERROR_RESULTS = ('This Custom Search Engine is loading. Try again in a few seconds.');
var _UDS_MSG_COUPONS = ('Coupons');
var _UDS_MSG_BACK = ('back');
var _UDS_MSG_SUBSCRIBE = ('Subscribe');
var _UDS_MSG_SEARCHER_PATENT = ('Patent');
var _UDS_MSG_USPAT = ('US Pat.');
var _UDS_MSG_USPAT_APP = ('US Pat. App');
var _UDS_MSG_PATENT_FILED = ('Filed');
var _UDS_MSG_ADS_BY_GOOGLE = ('Ads by Google');
var _UDS_MSG_SET_DEFAULT_LOCATION = ('Set default location');
var _UDS_MSG_NEWSCAT_TOPSTORIES = ('Top Stories');
var _UDS_MSG_NEWSCAT_WORLD = ('World');
var _UDS_MSG_NEWSCAT_NATION = ('Nation');
var _UDS_MSG_NEWSCAT_BUSINESS = ('Business');
var _UDS_MSG_NEWSCAT_SCITECH = ('Sci/Tech');
var _UDS_MSG_NEWSCAT_ENTERTAINMENT = ('Entertainment');
var _UDS_MSG_NEWSCAT_HEALTH = ('Health');
var _UDS_MSG_NEWSCAT_SPORTS = ('Sports');
var _UDS_MSG_NEWSCAT_POLITICS = ('Politics');
var _UDS_MSG_SEARCH_RESULTS = ('Search results');
var _UDS_MSG_DID_YOU_MEAN = ('Did you mean:');
var _UDS_MSG_CUSTOM_SEARCH = ('Custom Search');
var _UDS_MSG_LABELED = ('Labeled');
var _UDS_MSG_LOADING = ('Loading...');
var _UDS_MSG_ALL_RESULTS_SHORT = ('All');
var _UDS_MSG_ALL_RESULTS_LONG = ('All results');
var _UDS_MSG_REFINE_RESULTS = ('Refine results:');
function _UDS_MSG_REVIEWS(REVIEW_COUNT) {return ('' + REVIEW_COUNT + ' reviews');}
function _UDS_MSG_CALORIES(CALORIES) {return ('' + CALORIES + ' cal');}
function _UDS_MSG_PRICE_RANGE(RANGE) {return ('Price range: ' + RANGE + '.');}
function _UDS_MSG_PRICE(PRICE) {return ('Price: ' + PRICE + '.');}
function _UDS_MSG_AVAILABILITY(AVAILABILITY) {return ('Availability: ' + AVAILABILITY + '.');}
function _UDS_MSG_TELEPHONE(TELEPHONE) {return ('Tel: ' + TELEPHONE + '');}
function _UDS_MSG_RESULT_INFO(NUMBER_OF_RESULTS, SEARCH_TIME) {return ('About ' + NUMBER_OF_RESULTS + ' results (' + SEARCH_TIME + ' seconds)');}
var _UDS_MSG_FILE_FORMAT = ('File Format:');
var _UDS_MSG_SHOWING_RESULTS_FOR = ('Showing results for');
var _UDS_MSG_SEARCH_INSTEAD_FOR = ('Search instead for');
function _UDS_MSG_FILTERED_RESULTS(NUM) {return ('In order to show you the most relevant results, we have omitted some entries very similar to the ' + NUM + ' already displayed. If you like, you can ' + '<a>repeat the search with the omitted results included' + '</a>.');}
var _UDS_MSG_ORDER_BY = ('Sort by:');
var _UDS_MSG_ORDER_BY_RELEVANCE = ('Relevance');
var _UDS_MSG_ORDER_BY_DATE = ('Date');

var b=!0,g=null,h=encodeURIComponent,j=google_exportSymbol,k=window,l=document,m=navigator,n="appendChild",o="push",p="status",q="createElement",r="ServiceBase",s="length",t="language",u="style",v="loader",w={blank:"&nbsp;"};w.image=_UDS_MSG_SEARCHER_IMAGE;w.web=_UDS_MSG_SEARCHER_WEB;w.blog=_UDS_MSG_SEARCHER_BLOG;w.video=_UDS_MSG_SEARCHER_VIDEO;w.local=_UDS_MSG_SEARCHER_LOCAL;w.news=_UDS_MSG_SEARCHER_NEWS;w.book=_UDS_MSG_SEARCHER_BOOK;w.patent=_UDS_MSG_SEARCHER_PATENT;w["ads-by-google"]=_UDS_MSG_ADS_BY_GOOGLE;
w.save=_UDS_MSG_SEARCHCONTROL_SAVE;w.keep=_UDS_MSG_SEARCHCONTROL_KEEP;w.include=_UDS_MSG_SEARCHCONTROL_INCLUDE;w.copy=_UDS_MSG_SEARCHCONTROL_COPY;w.close=_UDS_MSG_SEARCHCONTROL_CLOSE;w["sponsored-links"]=_UDS_MSG_SEARCHCONTROL_SPONSORED_LINKS;w["see-more"]=_UDS_MSG_SEARCHCONTROL_SEE_MORE;w.watermark=_UDS_MSG_SEARCHCONTROL_WATERMARK;w["search-location"]=_UDS_MSG_SEARCHER_CONFIG_SET_LOCATION;w["disable-address-lookup"]=_UDS_MSG_SEARCHER_CONFIG_DISABLE_ADDRESS_LOOKUP;w["sort-by-date"]=_UDS_MSG_SORT_BY_DATE;
w.pbg=_UDS_MSG_BRANDING_STRING;w["n-minutes-ago"]=_UDS_MSG_MINUTES_AGO;w["n-hours-ago"]=_UDS_MSG_HOURS_AGO;w["one-hour-ago"]=_UDS_MSG_ONE_HOUR_AGO;w["all-n-related"]=_UDS_MSG_NEWS_ALL_N_RELATED;w["related-articles"]=_UDS_MSG_NEWS_RELATED;w["page-count"]=_UDS_MSG_TOTAL_PAGE_COUNT;var x=[];x[0]=_UDS_MSG_MONTH_ABBR_JAN;x[1]=_UDS_MSG_MONTH_ABBR_FEB;x[2]=_UDS_MSG_MONTH_ABBR_MAR;x[3]=_UDS_MSG_MONTH_ABBR_APR;x[4]=_UDS_MSG_MONTH_ABBR_MAY;x[5]=_UDS_MSG_MONTH_ABBR_JUN;x[6]=_UDS_MSG_MONTH_ABBR_JUL;x[7]=_UDS_MSG_MONTH_ABBR_AUG;
x[8]=_UDS_MSG_MONTH_ABBR_SEP;x[9]=_UDS_MSG_MONTH_ABBR_OCT;x[10]=_UDS_MSG_MONTH_ABBR_NOV;x[11]=_UDS_MSG_MONTH_ABBR_DEC;w["month-abbr"]=x;w.directions=_UDS_MSG_DIRECTIONS;w["clear-results"]=_UDS_MSG_CLEAR_RESULTS;w["show-one-result"]=_UDS_MSG_SHOW_ONE_RESULT;w["show-more-results"]=_UDS_MSG_SHOW_MORE_RESULTS;w["show-all-results"]=_UDS_MSG_SHOW_ALL_RESULTS;w.settings=_UDS_MSG_SETTINGS;w.search=_UDS_MSG_SEARCH;w["search-uc"]=_UDS_MSG_SEARCH_UC;w["powered-by"]=_UDS_MSG_POWERED_BY;w.sa=_UDS_MSG_SEARCHER_GSA;
w.by=_UDS_MSG_SEARCHER_BY;w.code=_UDS_MSG_SEARCHER_CODE;w["unknown-license"]=_UDS_MSG_UNKNOWN_LICENSE;w["more-results"]=_UDS_MSG_SEARCHCONTROL_MORERESULTS;w.previous=_UDS_MSG_SEARCHCONTROL_PREVIOUS;w.next=_UDS_MSG_SEARCHCONTROL_NEXT;w["get-directions"]=_UDS_MSG_GET_DIRECTIONS;w["to-here"]=_UDS_MSG_GET_DIRECTIONS_TO_HERE;w["from-here"]=_UDS_MSG_GET_DIRECTIONS_FROM_HERE;w["clear-results-uc"]=_UDS_MSG_CLEAR_RESULTS_UC;w["search-the-map"]=_UDS_MSG_SEARCH_THE_MAP;w["scroll-results"]=_UDS_MSG_SCROLL_THROUGH_RESULTS;
w["edit-tags"]=_UDS_MSG_EDIT_TAGS;w["tag-search"]=_UDS_MSG_TAG_THIS_SEARCH;w["search-string"]=_UDS_MSG_SEARCH_STRING;w["optional-label"]=_UDS_MSG_OPTIONAL_LABEL;w["delete"]=_UDS_MSG_DELETE;w.deleted=_UDS_MSG_DELETED;w.cancel=_UDS_MSG_CANCEL;w["upload-video"]=_UDS_MSG_UPLOAD_YOUR_VIDEOS;w["im-done"]=_UDS_MSG_IM_DONE_WATCHING;w["close-player"]=_UDS_MSG_CLOSE_VIDEO_PLAYER;w["no-results"]=_UDS_MSG_NO_RESULTS;w["linked-cse-error-results"]=_UDS_MSG_LINKEDCSE_ERROR_RESULTS;w.back=_UDS_MSG_BACK;
w.subscribe=_UDS_MSG_SUBSCRIBE;w["us-pat"]=_UDS_MSG_USPAT;w["us-pat-app"]=_UDS_MSG_USPAT_APP;w["us-pat-filed"]=_UDS_MSG_PATENT_FILED;w.dym=_UDS_MSG_DID_YOU_MEAN;w["showing-results-for"]=_UDS_MSG_SHOWING_RESULTS_FOR;w["search-instead-for"]=_UDS_MSG_SEARCH_INSTEAD_FOR;w["custom-search"]=_UDS_MSG_CUSTOM_SEARCH;w.labeled=_UDS_MSG_LABELED;w.loading=_UDS_MSG_LOADING;w["all-results-short"]=_UDS_MSG_ALL_RESULTS_SHORT;w["all-results-long"]=_UDS_MSG_ALL_RESULTS_LONG;w["refine-results"]=_UDS_MSG_REFINE_RESULTS;
w["result-info"]=_UDS_MSG_RESULT_INFO;w["file-format"]=_UDS_MSG_FILE_FORMAT;w["order-results-by"]="Sort by:";w["order-by-relevance"]="Relevance";w["order-by-date"]="Date";var _json_cache_defeater_=(new Date).getTime(),_json_request_require_prep=b;function y(a,d){z("msie")&&("msie 6.0"in A?A["msie 6.0"]:A["msie 6.0"]=-1!=m.appVersion.toLowerCase().indexOf("msie 6.0"))?k.setTimeout(B(this,C,[a,d]),0):C(a,d)}
function C(a,d){var c=l.getElementsByTagName("head")[0];c||(c=l.body.parentNode[n](l[q]("head")));var e=l[q]("script");e.type="text/javascript";e.charset="utf-8";var f=_json_request_require_prep?a+"&key="+google[v].ApiKey+"&v="+d:a;if(z("msie")||z("safari")||z("konqueror"))f=f+"&nocache="+_json_cache_defeater_++;e.src=f;var i=function(){e.onload=g;e.parentNode.removeChild(e);delete e},f=function(a){a=(a?a:k.event).target?(a?a:k.event).target:(a?a:k.event).srcElement;if("loaded"==a.readyState||"complete"==
a.readyState)a.onreadystatechange=g,i()};"Gecko"==m.product?e.onload=i:e.onreadystatechange=f;c[n](e)}function B(a,d,c){return function(){return d.apply(a,c||[])}}function z(a){return a in D?D[a]:D[a]=-1!=m.userAgent.toLowerCase().indexOf(a)}var D={},A={},E,F;k.ActiveXObject&&(E=b,k.XMLHttpRequest&&(F=b));if(!G)var G=j;if(!H)var H=google_exportProperty;
google[t].d={AFRIKAANS:"af",ALBANIAN:"sq",AMHARIC:"am",ARABIC:"ar",ARMENIAN:"hy",AZERBAIJANI:"az",BASQUE:"eu",BELARUSIAN:"be",BENGALI:"bn",BIHARI:"bh",BULGARIAN:"bg",BURMESE:"my",BRETON:"br",CATALAN:"ca",CHEROKEE:"chr",CHINESE:"zh",CHINESE_SIMPLIFIED:"zh-CN",CHINESE_TRADITIONAL:"zh-TW",CORSICAN:"co",CROATIAN:"hr",CZECH:"cs",DANISH:"da",DHIVEHI:"dv",DUTCH:"nl",ENGLISH:"en",ESPERANTO:"eo",ESTONIAN:"et",FAROESE:"fo",FILIPINO:"tl",FINNISH:"fi",FRENCH:"fr",FRISIAN:"fy",GALICIAN:"gl",GEORGIAN:"ka",GERMAN:"de",
GREEK:"el",GUJARATI:"gu",HAITIAN_CREOLE:"ht",HEBREW:"iw",HINDI:"hi",HUNGARIAN:"hu",ICELANDIC:"is",INDONESIAN:"id",INUKTITUT:"iu",IRISH:"ga",ITALIAN:"it",JAPANESE:"ja",JAVANESE:"jw",KANNADA:"kn",KAZAKH:"kk",KHMER:"km",KOREAN:"ko",KURDISH:"ku",KYRGYZ:"ky",LAO:"lo",LAOTHIAN:"lo",LATIN:"la",LATVIAN:"lv",LITHUANIAN:"lt",LUXEMBOURGISH:"lb",MACEDONIAN:"mk",MALAY:"ms",MALAYALAM:"ml",MALTESE:"mt",MAORI:"mi",MARATHI:"mr",MONGOLIAN:"mn",NEPALI:"ne",NORWEGIAN:"no",OCCITAN:"oc",ORIYA:"or",PASHTO:"ps",PERSIAN:"fa",
POLISH:"pl",PORTUGUESE:"pt",PORTUGUESE_PORTUGAL:"pt-PT",PUNJABI:"pa",QUECHUA:"qu",ROMANIAN:"ro",RUSSIAN:"ru",SANSKRIT:"sa",SCOTS_GAELIC:"gd",SERBIAN:"sr",SINDHI:"sd",SINHALESE:"si",SLOVAK:"sk",SLOVENIAN:"sl",SPANISH:"es",SUNDANESE:"su",SWAHILI:"sw",SWEDISH:"sv",SYRIAC:"syr",TAJIK:"tg",TAMIL:"ta",TAGALOG:"tl",TATAR:"tt",TELUGU:"te",THAI:"th",TIBETAN:"bo",TONGA:"to",TURKISH:"tr",UKRAINIAN:"uk",URDU:"ur",UZBEK:"uz",UIGHUR:"ug",VIETNAMESE:"vi",WELSH:"cy",YIDDISH:"yi",YORUBA:"yo",UNKNOWN:""};
G("google.language.Languages",google[t].d);
var I={AMHARIC:"am",ARMENIAN:"hy",AZERBAIJANI:"az",BASQUE:"eu",BENGALI:"bn",BIHARI:"bh",BRETON:"br",BURMESE:"my",CHEROKEE:"chr",CORSICAN:"co",DHIVEHI:"dv",ESPERANTO:"eo",FAROESE:"fo",FRISIAN:"fy",GEORGIAN:"ka",GUJARATI:"gu",INUKTITUT:"iu",JAVANESE:"jw",KANNADA:"kn",KAZAKH:"kk",KHMER:"km",KURDISH:"ku",KYRGYZ:"ky",LAO:"lo",LAOTHIAN:"lo",LATIN:"la",LUXEMBOURGISH:"lb",MALAYALAM:"ml",MAORI:"mi",MARATHI:"mr",MONGOLIAN:"mn",NEPALI:"ne",OCCITAN:"oc",ORIYA:"or",PASHTO:"ps",PUNJABI:"pa",QUECHUA:"qu",SANSKRIT:"sa",
SCOTS_GAELIC:"gd",SINDHI:"sd",SINHALESE:"si",SUNDANESE:"su",SYRIAC:"syr",TAJIK:"tg",TAMIL:"ta",TATAR:"tt",TELUGU:"te",TIBETAN:"bo",TONGA:"to",UIGHUR:"ug",URDU:"ur",UZBEK:"uz",YORUBA:"yo"},J={},K={},L=100;function M(a,d){var c="id"+L++;K[c]=function(e){e=d(e);a(e);delete K[c]};return"google.language.callbacks."+c}function N(a,d){var c="id"+L++;K[c]=function(e,f,i,R,U){e=d(e,f,i,R,U);a(e);delete K[c]};return"google.language.callbacks."+c}google[t].k=function(a){return J[a]};
G("google.language.isTranslatable",google[t].k);for(var O in google[t].d)J[google[t].d[O]]=b;for(O in I)J[I[O]]=!1;j("google.language.callbacks",K);
j("google.language.getBranding",function(a,d){var c="horizontal";d&&d.type&&(c=d.orientation);var e=w["powered-by"],f=google[v][r]+"/css/small-logo"+(E&&!F?".gif":".png"),i=['<div style="font-family:arial,sans-serif;','font-size:11px;margin-bottom:1px" class="gBrandingText">',e,'</div><div><img src="',f,'"/></div>'],e=['<span style="vertical-align:middle;font-family:arial,sans-serif;','font-size:11px;" class="gBrandingText">',e,'<img style="padding-left:1px;vertical-align:',E?'bottom;" ':'middle;" ',
'src="',f,'"/></span>'],e="horizontal"==c?e:i,f=e.join(""),c=l[q]("div");c.className="gBranding";c[u].color="#676767";e==i&&(c[u].textAlign="center");c.innerHTML=f;a&&(i=g,(i="string"==typeof a?l.getElementById(a):a)&&i[n]&&i[n](c));return c});j("google.language.HORIZONTAL_BRANDING","horizontal");j("google.language.VERTICAL_BRANDING","vertical");j("google.language.CurrentLocale",_UDS_CONST_LOCALE);j("google.language.ShortDatePattern",_UDS_CONST_SHORT_DATE_PATTERN);google[t].l=function(a,d,c){d=M(d,P);d="http://www.google.com/complete/search"+("?json=t&jsonp="+d+"&client=uds");c&&(d+="&hl="+h(c));d+="&q="+h(a);_json_request_require_prep=!1;y(d,g);_json_request_require_prep=b};G("google.language.suggest",google[t].l);function P(a){var d={};d.query=a[0];d.suggestions=[];for(var c=a[1],a=a[2],e=0;e<c[s];e++){var f={};f.name=c[e];f.count=parseInt(a[e].replace(",",""),10);f.results=a[e];d.suggestions[o](f)}return d};google[t].f={TEXT:"text",HTML:"html"};G("google.language.ContentType",google[t].f);google[t].translate=function(a,d,c,e){var f,i=g;if("string"==typeof a)f=a;else if(a.text&&a.type)f=a.text,i=a.type;else throw"Invalid first argument";5120>=f[s]?a=!1:(a=Q(g,g,400,"the string to be translated exceeds the maximum length allowed",g),e(a),a=b);a||(e=N(e,Q),e=google[v][r]+"/Gtranslate?callback="+e,e=e+"&context=22"+("&q="+h(f)),e+="&langpair="+h(d+"|"+c),i&&(e+="&format="+h(i)),y(e,google[t].Version))};
G("google.language.translate",google[t].translate);function Q(a,d,c,e){a={};a.status={code:c};e&&(a[p].message=e);200!=c?(a.error=a[p],a.translation=""):(a.translation=d.translatedText,d.detectedSourceLanguage&&(a.detectedSourceLanguage=d.detectedSourceLanguage));return a}google[t].i=function(a,d){var c=N(d,S),c=google[v][r]+"/GlangDetect?callback="+c,c=c+"&context=22"+("&q="+h(a));y(c,google[t].Version)};G("google.language.detect",google[t].i);
function S(a,d,c,e){a={};a.status={code:c};e&&(a[p].message=e);200!=c?(a.error=a[p],a.language=""):(a.language=d[t],a.isReliable=d.isReliable,a.confidence=d.confidence);return a};var T={"en|am":b,"en|ar":b,"en|bn":b,"en|el":b,"en|fa":b,"en|gu":b,"en|hi":b,"en|kn":b,"en|ml":b,"en|mr":b,"en|ne":b,"en|or":b,"en|pa":b,"en|ru":b,"en|sa":b,"en|si":b,"en|sr":b,"en|ta":b,"en|te":b,"en|ti":b,"en|ur":b,"en|zh":b};google[t].m=function(a,d,c,e){if("function"!=typeof e)throw"Invalid callback";if(V(a,d,c,e)){e=N(e,W);d=[google[v][r],"/Gtransliterate?callback=",e,"&context=22","&langpair=",h(d+"|"+c)];for(c=0;c<a[s];c++)d[o]("&q="),d[o](h(a[c]));y(d.join(""),google[t].Version)}};
G("google.language.transliterate",google[t].m);
function V(a,d,c,e){var f="";"object"!=typeof a||!a[s]?f="Words needs to be an array.":1>a[s]?f="No words to transliterate.":5<a[s]?f="Number of words to transliterate exceeds the limit of 5":d?c?d&&c&&T[d+"|"+c]||(f="Transliteration not supported for the language pair. Source Language - "+d+" Destination Language - "+c+"."):f="Destination language not specified.":f="Source language not specified.";if(0<f[s]){var i=W(g,g,400,f,g);k.setTimeout(function(){e(i)},0);return!1}return b}
function W(a,d,c,e){a={status:{code:c,message:e}};200!=c?(a.error=a[p],a.transliterations=[]):a.transliterations=d.transliterations;return a};var X={hi:b,kn:b,ml:b,ta:b,te:b};google[t].c={h:0,g:1,e:2};google[t].j=function(a){a=a.toLowerCase();return a in X?Y(a):google[t].c.e};G("google.language.FontRenderingStatus.SUPPORTED",google[t].c.g);G("google.language.FontRenderingStatus.UNSUPPORTED",google[t].c.h);G("google.language.FontRenderingStatus.UNKNOWN",google[t].c.e);G("google.language.isFontRenderingSupported",google[t].j);
function Y(a){switch(a){case "ml":return a=[],a[o]({a:"\u0d23\u0d28\u0d4d\u200d",b:"\u0d23\u0d4d\u0d23\u0d28\u0d4d\u0d31"}),a[o]({a:"\u0d23\u0d28\u0d4d\u200d",b:"\u0d23\u0d4d\u0d23\u0d28\u0d4d\u200d\u0d31"}),Z(a);case "hi":return Z([{a:"\u0915\u094d\u0930\u0930\u094d\u0925",b:"\u0915\u0925"}]);case "kn":return Z([{a:"\u0c95\u0ccd\u0cb2",b:"\u0c95"}]);case "te":return Z([{a:"\u0c15\u0c4d\u0c32",b:"\u0c15"}]);case "ta":return Z([{a:"\u0b95\u0bcd",b:"\u0b95"}])}}
function Z(a){for(var d=0;d<a[s];d++){var c=a[d],e=c.a,f=c.b,c=l[q]("span");c[u].fontSize="10px";var i=c[u];"opacity"in i?i.opacity=0.1:"MozOpacity"in i?i.MozOpacity=0.1:"filter"in i&&(i.filter="alpha(opacity=10)");l.body[n](c);c.innerHTML=e;e=$(c).width;c.innerHTML=f;f=$(c).width;l.body.removeChild(c);if(e==f)return b}return!1}
function $(a){if("none"!=a[u].display)return{width:a.offsetWidth,height:a.offsetHeight};var d=a[u],c=d.display,e=d.visibility,f=d.position;d.visibility="hidden";d.position="absolute";d.display="";var i=a.offsetWidth,a=a.offsetHeight;d.display=c;d.position=f;d.visibility=e;return{width:i,height:a}};
google.loader.loaded({"module":"language","version":"1.0","components":["default"]});
google.loader.eval.language = function() {eval(arguments[0]);};if (google.loader.eval.scripts && google.loader.eval.scripts['language']) {(function() {var scripts = google.loader.eval.scripts['language'];for (var i = 0; i < scripts.length; i++) {google.loader.eval.language(scripts[i]);}})();google.loader.eval.scripts['language'] = null;}})();