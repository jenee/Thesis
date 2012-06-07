(function(){var e=void 0,g=!0,h=null,i=!1,k,l=this,aa=function(a){var b=typeof a;if("object"==b)if(a){if(a instanceof Array)return"array";if(a instanceof Object)return b;var c=Object.prototype.toString.call(a);if("[object Window]"==c)return"object";if("[object Array]"==c||"number"==typeof a.length&&"undefined"!=typeof a.splice&&"undefined"!=typeof a.propertyIsEnumerable&&!a.propertyIsEnumerable("splice"))return"array";if("[object Function]"==c||"undefined"!=typeof a.call&&"undefined"!=typeof a.propertyIsEnumerable&&
!a.propertyIsEnumerable("call"))return"function"}else return"null";else if("function"==b&&"undefined"==typeof a.call)return"object";return b},m=function(a){return"array"==aa(a)},n=function(a){return"string"==typeof a},p=function(a){return"number"==typeof a},r=function(a){return"function"==aa(a)};Math.floor(2147483648*Math.random()).toString(36);
var ba=function(a,b,c){return a.call.apply(a.bind,arguments)},ca=function(a,b,c){if(!a)throw Error();if(2<arguments.length){var d=Array.prototype.slice.call(arguments,2);return function(){var c=Array.prototype.slice.call(arguments);Array.prototype.unshift.apply(c,d);return a.apply(b,c)}}return function(){return a.apply(b,arguments)}},t=function(a,b,c){t=Function.prototype.bind&&-1!=Function.prototype.bind.toString().indexOf("native code")?ba:ca;return t.apply(h,arguments)},u=function(a,b){function c(){}
c.prototype=b.prototype;a.xb=b.prototype;a.prototype=new c};var v=function(){return l.googletag||(l.googletag={})},w=function(a,b,c){var d=v();if(!(a in d)||c)d[a]=b},da=function(a,b){a.attachEvent?a.attachEvent("onload",b):a.addEventListener&&a.addEventListener("load",b,i)};var x=function(a,b,c,d,f){this.Y=new Date;this.Qa=d||h;this.Pa=c||h;this.va=a;this.wa=b;this.X=f||h};k=x.prototype;k.Ia=function(){return this.Qa};k.Ha=function(){return this.Pa};k.Ga=function(){return this.va};k.Ca=function(){return this.Y};k.hb=function(){return this.wa};k.jb=function(){return this.X};var ea=["Debug","Info","Warning","Error","Fatal"];
x.prototype.toString=function(){var a=this.Y.toTimeString()+": "+ea[this.va]+": "+this.wa;this.X&&(a+=" Duration: "+(this.Y.getTime()-this.X.Ca().getTime())+"ms.");return a};x.prototype.getTimestamp=x.prototype.Ca;x.prototype.getService=x.prototype.Ha;x.prototype.getSlot=x.prototype.Ia;x.prototype.getLevel=x.prototype.Ga;x.prototype.getMessage=x.prototype.hb;x.prototype.getReference=x.prototype.jb;var A=function(){this.B=[]};A.prototype.$a=function(){return this.B};A.prototype.eb=function(a){return fa(this,function(b){return b.Ha()===a})};A.prototype.fb=function(a){return fa(this,function(b){return b.Ia()===a})};A.prototype.cb=function(a){return fa(this,function(b){return b.Ga()>=a})};var fa=function(a,b){for(var c=[],d=0;d<a.B.length;++d)b(a.B[d])&&c.push(a.B[d]);return c};A.prototype.log=function(a,b,c,d,f){a=new x(a,b,c,d,f);this.B.push(a);return a};
A.prototype.info=function(a,b,c,d){return this.log(1,a,b,c,d)};var B=function(a,b,c,d){a.log(2,b,c,d,e)};A.prototype.error=function(a,b,c,d){return this.log(3,a,b,c,d)};var C=function(){var a=v();return a.debug_log||(a.debug_log=new A)};w("getEventLog",C);A.prototype.getAllEvents=A.prototype.$a;A.prototype.getEventsByService=A.prototype.eb;A.prototype.getEventsBySlot=A.prototype.fb;A.prototype.getEventsByLevel=A.prototype.cb;var D=function(){this.Da=this.ca=0};D.prototype.push=function(a){for(var b=C(),c=0;c<arguments.length;++c)try{r(arguments[c])&&(arguments[c](),this.ca++)}catch(d){this.Da++,b.error("Exception invoking function: "+d.message)}b.info("Invoked queued function. Total: "+this.ca+" Errors: "+this.Da);return this.ca};D.prototype.push=D.prototype.push;function ga(a){this.t={};this.tick=function(a,c,d){this.t[a]=[d!=e?d:(new Date).getTime(),c]};this.tick("start",h,a)}var ha=new ga;window.GPT_jstiming={Timer:ga,load:ha};try{var E=h;window.chrome&&window.chrome.csi&&(E=Math.floor(window.chrome.csi().pageT));E==h&&window.gtbExternal&&(E=window.gtbExternal.pageT());E==h&&window.external&&(E=window.external.pageT);E&&(window.GPT_jstiming.pt=E)}catch(ia){};if(window.GPT_jstiming){window.GPT_jstiming.Fa={};window.GPT_jstiming.Ra=1;var ja=function(a,b,c){var d=a.t[b],f=a.t.start;if(d&&(f||c))return d=a.t[b][0],c!=e?f=c:f=f[0],d-f},ka=function(a,b,c){var d="";window.GPT_jstiming.pt&&(d+="&srt="+window.GPT_jstiming.pt,delete window.GPT_jstiming.pt);try{window.external&&window.external.tran?d+="&tran="+window.external.tran:window.gtbExternal&&window.gtbExternal.tran?d+="&tran="+window.gtbExternal.tran():window.chrome&&window.chrome.csi&&(d+="&tran="+window.chrome.csi().tran)}catch(f){}var j=
window.chrome;if(j&&(j=j.loadTimes)){j().wasFetchedViaSpdy&&(d+="&p=s");if(j().wasNpnNegotiated){var d=d+"&npn=1",o=j().npnNegotiatedProtocol;o&&(d+="&npnv="+(encodeURIComponent||escape)(o))}j().wasAlternateProtocolAvailable&&(d+="&apa=1")}var y=a.t,G=y.start,j=[],o=[],s;for(s in y)if("start"!=s&&0!=s.indexOf("_")){var q=y[s][1];q?y[q]&&o.push(s+"."+ja(a,s,y[q][0])):G&&j.push(s+"."+ja(a,s))}delete y.start;if(b)for(var z in b)d+="&"+z+"="+b[z];(b=c)||(b="https:"==document.location.protocol?"https://csi.gstatic.com/csi":
"http://csi.gstatic.com/csi");return[b,"?v=3","&s="+(window.GPT_jstiming.sn||"gpt")+"&action=",a.name,o.length?"&it="+o.join(","):"","",d,"&rt=",j.join(",")].join("")},la=function(a,b,c){a=ka(a,b,c);if(!a)return"";var b=new Image,d=window.GPT_jstiming.Ra++;window.GPT_jstiming.Fa[d]=b;b.onload=b.onerror=function(){window.GPT_jstiming&&delete window.GPT_jstiming.Fa[d]};b.src=a;b=h;return a};window.GPT_jstiming.report=function(a,b,c){if("prerender"==document.webkitVisibilityState){var d=i,f=function(){if(!d){b?
b.prerender="1":b={prerender:"1"};var j;"prerender"==document.webkitVisibilityState?j=i:(la(a,b,c),j=g);j&&(d=g,document.removeEventListener("webkitvisibilitychange",f,i))}};document.addEventListener("webkitvisibilitychange",f,i);return""}return la(a,b,c)}};var F,ma,H,na,oa=function(){return l.navigator?l.navigator.userAgent:h};na=H=ma=F=i;var I;if(I=oa()){var pa=l.navigator;F=0==I.indexOf("Opera");ma=!F&&-1!=I.indexOf("MSIE");H=!F&&-1!=I.indexOf("WebKit");na=!F&&!H&&"Gecko"==pa.product}var J=ma,qa=na,ra=H,sa;
a:{var K="",L;if(F&&l.opera)var ta=l.opera.version,K="function"==typeof ta?ta():ta;else if(qa?L=/rv\:([^\);]+)(\)|;)/:J?L=/MSIE\s+([^\);]+)(\)|;)/:ra&&(L=/WebKit\/(\S+)/),L)var ua=L.exec(oa()),K=ua?ua[1]:"";if(J){var va,wa=l.document;va=wa?wa.documentMode:e;if(va>parseFloat(K)){sa=""+va;break a}}sa=K}
var xa=sa,ya={},za=function(a){if(!ya[a]){for(var b=0,c=(""+xa).replace(/^[\s\xa0]+|[\s\xa0]+$/g,"").split("."),d=(""+a).replace(/^[\s\xa0]+|[\s\xa0]+$/g,"").split("."),f=Math.max(c.length,d.length),j=0;0==b&&j<f;j++){var o=c[j]||"",y=d[j]||"",G=RegExp("(\\d*)(\\D*)","g"),s=RegExp("(\\d*)(\\D*)","g");do{var q=G.exec(o)||["","",""],z=s.exec(y)||["","",""];if(0==q[0].length&&0==z[0].length)break;b=((0==q[1].length?0:parseInt(q[1],10))<(0==z[1].length?0:parseInt(z[1],10))?-1:(0==q[1].length?0:parseInt(q[1],
10))>(0==z[1].length?0:parseInt(z[1],10))?1:0)||((0==q[2].length)<(0==z[2].length)?-1:(0==q[2].length)>(0==z[2].length)?1:0)||(q[2]<z[2]?-1:q[2]>z[2]?1:0)}while(0==b)}ya[a]=0<=b}},Aa={},Ba=function(){return Aa[9]||(Aa[9]=J&&!!document.documentMode&&9<=document.documentMode)};!J||Ba();!qa&&!J||J&&Ba()||qa&&za("1.9.1");J&&za("9");var M=function(a,b){this.Ta=a;this.Sa=b};M.prototype.mb=function(){return this.Ta};M.prototype.gb=function(){return this.Sa};M.prototype.getWidth=M.prototype.mb;M.prototype.getHeight=M.prototype.gb;var N=function(a,b,c){this.s=a;this.za=p(b)?b:0;this.f=this.s+"_"+this.za;this.Oa=c||"gpt_unit_"+this.f};k=N.prototype;k.o=function(){return this.f};k.getName=function(){return this.s};k.Ba=function(){return this.za};k.toString=N.prototype.o;k.k=function(){return this.Oa};N.prototype.getId=N.prototype.o;N.prototype.getName=N.prototype.getName;N.prototype.getDomId=N.prototype.k;N.prototype.getInstance=N.prototype.Ba;var Ca=function(a){return a.replace(/[^a-zA-Z0-9]/g,function(a){return"&#"+a.charCodeAt()+";"})},Da=function(){var a=h;try{a=document.location.protocol}catch(b){}return"https:"==a?"https:":"http:"};var O=function(a,b,c,d){this.s=a;var f=[];if(m(c))if(1<c.length&&p(c[0])&&p(c[1]))f.push(new M(c[0],c[1]));else for(var j=0;j<c.length;++j){var o=c[j];m(o)&&(1<o.length&&p(o[0])&&p(o[1]))&&f.push(new M(o[0],o[1]))}this.Ka=f;this.f=new N(a,b,d);this.c=[];this.h={};this.m=h;this.b=C();this.b.info("Created slot: "+this.f,h,this);this.r=this.F=h;this.ka=this.ja="";this.L=g;this.g={};this.la=i};k=O.prototype;
k.set=function(a,b){var c=[" attribute ",a," with value ",b," for slot ",this.getName()].join("");a&&n(a)&&b?(this.h[a]=b,this.F||this.r?B(this.b,"Setting"+c+" after its contents have been loaded",h,this):this.b.info("Setting"+c,h,this)):B(this.b,"Unable to set"+c,h,this);return this};k.get=function(a){return a in this.h?this.h[a]:h};k.w=function(){var a=[],b;for(b in this.h)r(this.h[b])||a.push(b);return a};
k.xa=function(a){for(var b=0;b<this.c.length;++b)if(a==this.c[b])return B(this.b,"Service "+a.getName()+" is already associated with slot "+this.f,a,this),this;this.c.push(a);a.T(this);return this};k.getName=function(){return this.s};k.i=function(){return this.f};k.kb=function(){return this.c};k.lb=function(){return this.Ka};k.u=function(){return!!document.getElementById(this.f.k())};k.K=function(a){this.m=a};k.ya=function(a){this.ka=a;return this};k.U=function(){return this.ka};
k.da=function(a,b){var c=[];m(b)?c=b:b&&c.push(b.toString());var d=[" targeting attribute ",a," with value ",c.join()," for slot ",this.getName()].join("");if(a&&n(a)){if(this.b.info("Setting"+d,h,this),this.g[a]=c,this.F||this.r)for(d=0;d<this.c.length;++d){var f=this.c[d];f.isEnabled()&&f.oa(this,a,c)}}else B(this.b,"Unable to set"+d,h,this);return this};k.Ua=function(){this.b.info("Clearing slot targeting.",h,this);this.g={};for(var a=0;a<this.c.length;++a){var b=this.c[a];b.isEnabled()&&b.clearSlotTargeting(this)}return this};
k.ib=function(){return this.la};var Ea=function(a){if(!a.u())return a.b.error("Unable to write to slot "+a.f+". It has not yet been rendered.",h,a),i;var b=l.document,c=a.f.k(),b=b&&b.getElementById(c);if(!b)return a.b.error("Unable to find the div container with id "+c+" for slot "+a.f,h,a),i;c=a.m;return n(c)&&0<c.length?(a.qa(),b.innerHTML=c,a.pa(),g):i};k=O.prototype;k.Za=function(a){this.F=this.b.info("Fetching ad for slot "+this.getName(),h,this);this.ja=a};k.ab=function(){return this.ja};
k.Ya=function(){this.b.info("Receiving ad for slot "+this.getName(),h,this,this.F)};k.qa=function(){this.r=this.b.info("Rendering ad for slot "+this.getName(),h,this)};k.pa=function(){this.b.info("Completed rendering ad for slot "+this.getName(),h,this,this.r)};O.prototype.set=O.prototype.set;O.prototype.get=O.prototype.get;O.prototype.getName=O.prototype.getName;O.prototype.getSlotId=O.prototype.i;O.prototype.getSizes=O.prototype.lb;O.prototype.addService=O.prototype.xa;
O.prototype.getOutOfPage=O.prototype.ib;O.prototype.getServices=O.prototype.kb;O.prototype.getAttributeKeys=O.prototype.w;O.prototype.fetchStarted=O.prototype.Za;O.prototype.fetchEnded=O.prototype.Ya;O.prototype.renderStarted=O.prototype.qa;O.prototype.renderEnded=O.prototype.pa;O.prototype.hasWrapperDiv=O.prototype.u;O.prototype.getContentUrl=O.prototype.ab;O.prototype.setClickUrl=O.prototype.ya;O.prototype.getClickUrl=O.prototype.U;O.prototype.clearTargeting=O.prototype.Ua;
O.prototype.setTargeting=O.prototype.da;var P=function(){this.A={};this.G={};this.b=C()};P.prototype.add=function(a,b,c){if(!n(a)||0>=a.length||!b)return h;a in this.A||(this.A[a]=[]);b=new O(a,this.A[a].length,b,c);c=b.i().k();if(this.G[c])return this.b.error("Div element "+c+" is already associated with another slot"),h;this.A[a].push(b);return this.G[b.i().k()]=b};P.prototype.find=function(a,b){var c=b||0,d=n(a)&&this.A[a]||[];return 0<=c&&c<d.length&&(d=d[c],d.i().Ba()==c)?d:h};
var Q=function(){var a=v();return a.slot_manager_instance||(a.slot_manager_instance=new P)},R=function(a,b,c){var d=Q();return d&&d.add(a,b,c)};w("defineOutOfPageSlot",function(a,b){var c=Q();return!c?h:(c=c.add(a,[1,1],b))?(c.la=g,c):h});w("defineSlot",R);w("defineUnit",R);P.prototype.find=P.prototype.find;P.getInstance=Q;var Fa=function(a){var b=C();if(n(a)){var c;c=Q();c.G[a]?c=c.G[a]:(B(c.b,"Ad unit lookup for div "+a+" failed."),c=h);if(c)if(a=c,a.L&&!a.u())B(a.b,"Slot "+a.s+" does not have a container div with id: "+a.f.k()+".",h,a);else for(b=0;b<a.c.length;++b)a.c[b].isEnabled()&&a.c[b].C(a);else b.error("Div "+a+" is not mapped to a known ad unit.")}else b.error("Unknown div id in display(): "+a.toString())};w("display",Fa,g);var S=function(){this.ta=[];this.ua={};this.Z=i;this.h={};this.log=C();this.log.info("Created service: "+this.getName(),this)};k=S.prototype;k.getName=function(){return"unknown"};k.set=function(a,b){var c=["attribute ",a," with value ",b," for service ",this.getName()].join("");n(a)&&0<a.length?(this.h[a]=b,this.log.info("Setting "+c,this,h)):B(this.log,"Unable to set "+c,this,h);return this};k.get=function(a){return this.h[a]};
k.w=function(){var a=[],b;for(b in this.h)"function"!=typeof this.h[b]&&a.push(b);return a};k.l=function(){return this.ta};k.Ea=function(){return this.ua};k.isEnabled=function(){return this.Z};k.enable=function(){if(this.Z)this.log.info("Service is already enabled.",this);else{this.Z=g;try{this.ba()}catch(a){this.log.error("Failed to enable service: "+a,this)}}};k.display=function(a,b,c,d){this.enable();a=c?R(a,b,c):R(a,b);a.xa(this);d&&a.ya(d);Fa(a.i().k())};
k.T=function(a){this.ta.push(a);this.ua[a.i().o()]=a;this.log.info("Associated "+this.getName()+" service with slot "+a.getName(),this,a)};k.clearSlotTargeting=function(){};k.oa=function(){};S.prototype.getSlots=S.prototype.l;S.prototype.getSlotIdMap=S.prototype.Ea;S.prototype.enable=S.prototype.enable;S.prototype.set=S.prototype.set;S.prototype.get=S.prototype.get;S.prototype.getAttributeKeys=S.prototype.w;S.prototype.display=S.prototype.display;var Ga=function(a,b){this.name=a;this.aa=b?b:new l.GPT_jstiming.Timer;this.aa.name=a;this.$=[]};k=Ga.prototype;k.getName=function(){return this.name};k.tick=function(a,b){this.aa.tick(a,b)};k.Aa=function(a){a&&this.$.push(a)};k.report=function(){var a="https:"==l.location.protocol?"https://www.google.com/csi":"http://csi.gstatic.com/csi",b={};this.$.length&&(b.e=this.$.join());return l.GPT_jstiming.report(this.aa,b,a)};k.Ja=function(a){da(window,function(){setTimeout(a,10)})};
var T=function(a){this.name=a};u(T,Ga);T.prototype.tick=function(){};T.prototype.Aa=function(){};T.prototype.report=function(){return h};T.prototype.Ja=function(){};var Ha=function(){var a=l.GPT_jstiming.load,b=0.01;b==e&&(b=0.01);return l.GPT_jstiming&&l.GPT_jstiming.load&&("http:"==l.location.protocol||"https:"==l.location.protocol)&&Math.random()<b?new Ga("global",a):new T("global")};
(function(){if(!v()._gpt_timer_&&l.GPT_jstiming){var a=Ha();a.Ja(function(){a.tick("load");a.report()});w("_gpt_timer_",a)}return v()._gpt_timer_})();var U=function(){this.c={};this.N=i;this.b=C();this.Ma=this.b.info("Google service JS loaded");da(window,t(U.prototype.Na,this))};U.prototype.add=function(a){this.c[a.getName()]=a};U.prototype.find=function(a){var b=h;a in this.c&&(b=this.c[a]);return b};U.prototype.Na=function(){this.N=g;this.b.info("Page load complete",h,h,this.Ma)};var V=function(){var a=v();return a.service_manager_instance||(a.service_manager_instance=new U)};
w("enableServices",function(){var a=V(),b;for(b in a.c){var c=a.c[b];if(!r(c)){c.enable();var c=b,d=v()._gpt_timer_;d&&d.Aa(c)}}});var W=function(){S.call(this);this.ma=g;this.W=i;this.I=0;this.J="";this.S=this.R=this.Q=this.z=e;this.na=this.V=i;this.P={};this.H=i};u(W,S);k=W.prototype;
k.ba=function(){if(this.ma){if(!this.na){var a=document,b=document.createElement("script");b.async=g;b.type="text/javascript";b.src=this.n();try{var c=a.getElementsByTagName("script")[0];this.log.info("Fetching companion ads implementation",this);this.na=g;c.parentNode&&c.parentNode.insertBefore(b,c)}catch(d){this.log.error("Unable to fetch companion ads implementation",this)}}}else this.V||(l.document.write('<script type="text/javascript" src="'+Ca(this.n())+'"><\/script>'),this.V=g)};
k.Va=function(){this.ma=i};k.sb=function(a){"boolean"==typeof a&&(this.W=a)};k.ob=function(a){if(this.W){for(var b=this.Ea(),c=[],d=0;d<a.length;++d){var f=a[d];f in b?c.push(b[f]):B(this.log,"Cannot find slot with id "+f+".",this)}Ia(this,c)}};k.ra=function(){var a=googletag.pubads();if(!a.isEnabled())return i;var a=a.l(),b=this.l();if(a.length!=b.length)return i;for(var c=0;c<b.length;++c){for(var d=i,f=0;f<a.length;++f)if(b[c]===a[f]){d=g;break}if(!d)return i}return g};
k.rb=function(){this.W&&Ia(this,h)};
k.ub=function(a,b,c,d,f,j,o){this.H=i;this.I=0;this.J="";this.S=this.R=this.Q=this.z=e;this.I=a;this.J=b;this.z=c;0==this.z.length&&(this.z=e);a:{a=d.split(",");b=[];for(c=0;c<a.length;++c){d=a[c].split("x");if(2!=d.length){this.log.error("The master ad size specified is invalid.");a=e;break a}d=[Number(d[0]),Number(d[1])];if(isNaN(d[0])||isNaN(d[1])){this.log.error("The master ad size specified is invalid.");a=e;break a}b.push(d)}a=b}this.Q=a;f!==e&&(this.R=f);j!==e&&(this.S=j);o!==e&&(this.H=o)};
k.bb=function(){return googletag.pubads().getCorrelator()};k.vb=function(a){this.I=a};k.wb=function(a){this.J=a};var Ia=function(a,b){var c=googletag.pubads();if(c.isEnabled()){if(a.H){if(!a.ra()){B(a.log,"Persistent roadblock requested, but ad slots are incorrectly configured. All ad slots on page must have both pubads and companionAds services attached. Skipping refresh.");return}c.clearNoRefreshState();c.clear()}c.sa(b,a.I,a.J,a.z,a.Q,a.R,a.S,a.H)}else a.log.error("Pubads service is not enabled, cannot use refresh feature.")};
k=W.prototype;k.isSlotAPersistentRoadblock=function(a){var b=googletag.pubads();if(b.isEnabled())return b.isSlotAPersistentRoadblock(a);this.log.error("Pubads service is not enabled, cannot check whether slot is a persistent roadblock.  Content writing allowed.");return i};k.getName=function(){return"companion_ads"};k.n=function(){return Da()+"//pagead2.googlesyndication.com/pagead/show_companion_ad.js"};k.qb=function(){this.log.info("Companion ads implementation fetched.",this);this.V=g};
k.p=function(a){var b=a&&a.i().o();return b&&b in this.P&&a.u()&&this.isEnabled()&&!this.isSlotAPersistentRoadblock(a)?(a.K(this.P[b]),Ea(a)):i};k.C=function(a){this.p(a)};k.fillSlot=function(a,b){return a&&n(b)&&0<b.length?(this.P[a.i().toString()]=b,this.p(a)):i};w("companionAds",function(){var a=V(),b=a.find("companion_ads");b||(b=new W,a.add(b));return b});W.prototype.fillSlot=W.prototype.fillSlot;W.prototype.enableSyncLoading=W.prototype.Va;W.prototype.isSlotAPersistentRoadblock=W.prototype.isSlotAPersistentRoadblock;
W.prototype.isRoadblockingSupported=W.prototype.ra;W.prototype.onImplementationLoaded=W.prototype.qb;W.prototype.notifyUnfilledSlots=W.prototype.ob;W.prototype.refreshAllSlots=W.prototype.rb;W.prototype.setRefreshUnfilledSlots=W.prototype.sb;W.prototype.setXfpCorrelator=W.prototype.vb;W.prototype.setXfpPreviousAdsToken=W.prototype.wb;W.prototype.setVideoSessionInfo=W.prototype.ub;W.prototype.getDisplayAdsCorrelator=W.prototype.bb;var X=function(){S.call(this);this.m={}};u(X,S);k=X.prototype;k.getName=function(){return"content"};k.p=function(a){var b=a&&a.i().o();return b in this.m&&this.isEnabled()&&a.u()&&!a.r?(a.K(this.m[b]),Ea(a)):i};k.ba=function(){for(var a=this.l(),b=0;b<a.length;++b)this.p(a[b])};k.C=function(a){this.p(a)};k.K=function(a,b){a&&(n(b)&&0<b.length)&&(this.m[a.i().o()]=b,this.p(a))};w("content",function(){var a=V(),b=a.find("content");b||(b=new X,a.add(b));return b});X.prototype.setContent=X.prototype.K;var Y=function(){S.call(this);this.v=i;this.a=h;this.g={};this.ga=i;this.fa=g;this.q=this.ea=i;this.d=g;this.D=i;this.j=[];this.O=i;this.ha=this.ia="";this.M=g};u(Y,S);
var Z={adsense_ad_format:"google_ad_format",adsense_ad_types:"google_ad_type",adsense_allow_expandable_ads:"google_allow_expandable_ads",adsense_background_color:"google_color_bg",adsense_bid:"google_bid",adsense_border_color:"google_color_border",adsense_channel_ids:"google_ad_channel",adsense_content_section:"google_ad_section",adsense_cpm:"google_cpm",adsense_ed:"google_ed",adsense_encoding:"google_encoding",adsense_family_safe:"google_safe",adsense_feedback:"google_feedback",adsense_flash_version:"google_flash_version",
adsense_font_face:"google_font_face",adsense_font_size:"google_font_size",adsense_hints:"google_hints",adsense_host:"google_ad_host",adsense_host_channel:"google_ad_host_channel",adsense_host_tier_id:"google_ad_host_tier_id",adsense_keyword_type:"google_kw_type",adsense_keywords:"google_kw",adsense_line_color:"google_line_color",adsense_link_color:"google_color_link",adsense_relevant_content:"google_contents",adsense_reuse_colors:"google_reuse_colors",adsense_targeting:"google_targeting",adsense_targeting_types:"google_targeting",
adsense_test_mode:"google_adtest",adsense_text_color:"google_color_text",adsense_ui_features:"google_ui_features",adsense_ui_version:"google_ui_version",adsense_url_color:"google_color_url",alternate_ad_iframe_color:"google_alternate_color",alternate_ad_url:"google_alternate_ad_url",demographic_age:"google_cust_age",demographic_ch:"google_cust_ch",demographic_gender:"google_cust_gender",demographic_interests:"google_cust_interests",demographic_job:"google_cust_job",demographic_l:"google_cust_l",demographic_lh:"google_cust_lh",
demographic_u_url:"google_cust_u_url",demographic_unique_id:"google_cust_id",document_language:"google_language",geography_override_city:"google_city",geography_override_country:"google_country",geography_override_region:"google_region",page_url:"google_page_url"};k=Y.prototype;
k.ba=function(){if(this.d){if(!this.v){var a=document,b=a.createElement("script");V();b.async=g;b.type="text/javascript";b.src=this.n();(a=a.getElementsByTagName("head")[0]||a.getElementsByTagName("body")[0])?(this.log.info("Fetching GPT implementation",this),a.appendChild(b),this.v=g):this.log.error("Unable to fetch GPT implementation",this)}}else b=V(),!this.v&&!b.N&&(this.v=g,document.write('<script type="text/javascript" src="'+Ca(this.n())+'"><\/script>'))};k.getName=function(){return"publisher_ads"};
k.n=function(){var a=Da();return this.M?a+"//partner.googleadservices.com/gampad/google_ads_gpt.js":a+"//partner.googleadservices.com/gampad/google_ads_gpt_mobile.js"};
k.pb=function(){V();var a=v().impl;if(a&&(!this.M&&a.pubads_mobile||a.pubads)){this.a=!this.M&&a.pubads_mobile||a.pubads;this.log.info("GPT implementation fetched.",this);this.fa||this.a.disableFetch();this.D&&this.a.collapseEmptyDivs();if(this.q){this.d?this.a.enableAsyncSingleRequest():this.a.enableSingleRequest();Ja(this);for(var a=this.l(),b=0;b<a.length;++b)Ka(this,a[b])}else this.d&&this.a.enableAsyncRendering();this.ea&&this.a.disableInitialLoad();La(this);if(0<this.j.length)for(b=0;b<this.j.length;++b)this.C(this.j[b])}else this.log.error("Unable to fetch pubads service implementation from "+
this.n(),this)};k.T=function(a){this.d||(a.L=i);S.prototype.T.call(this,a)};
k.C=function(a){if(V().N&&!this.d)this.log.error("Attempting to display ad in sync mode after page load is complete.",this);else if(this.a){if(Ja(this),this.q||Ka(this,a))this.log.info("Calling fillslot"),this.a.fillSlot(a)}else if(this.d||this.v&&0==this.j.length){for(var b=i,c=0;c<this.j.length;++c)a===this.j[c]&&(b=g);b||(this.log.info("Delaying rendering of ad slot "+a.getName()+" pending loading of the GPT implementation",this,a),this.j.push(a))}else this.log.error("Skipping rendering of slot "+
a.getName()+" due to missing GPT implementaition",this,a)};
var Ka=function(a,b){if(a.a&&a.a.addSlot(b)==h)return a.log.error("Unable to process name for slot "+b.getName(),a,b),i;for(var c=b.w(),d=0;d<c.length;++d)c[d]in Z?a.a.addAdSenseSlotAttribute(b,Z[c[d]],b.get(c[d])):B(a.log,"Ignoring unknown pubads attribute "+c[d]+" with value "+b.get(c[d])+" for slot "+b.getName(),a,b);if(r(a.a.addSlotTargeting)){var c=[],f;for(f in b.g)r(b.g[f])||c.push(f);for(f=0;f<c.length;++f)a.a.addSlotTargeting(b,c[f],c[f]in b.g?b.g[c[f]]:[])}b.U()&&r(a.a.La)&&a.a.La(b,b.U());
return g},Ja=function(a){if(!a.ga){a.ga=g;for(var b=a.w(),c=0;c<b.length;++c)b[c]in Z?a.a.addAdSensePageAttribute(Z[b[c]],a.get(b[c])):B(a.log,"Ignoring unknown pubads attribute "+b[c]+" with value "+a.get(b[c]),a);a.a.addAdSensePageAttribute("google_tag_info","v2");for(var d in a.g)if(b=a.g[d],m(b))for(c=0;c<b.length;++c)a.a.addAttribute(d,b[c])}};k=Y.prototype;
k.da=function(a,b){var c=[];n(b)?c.push(b):c=b;var d=[" targeting attribute ",a," with value ",c.join()," for service ",this.getName()].join("");a&&n(a)?(this.g[a]=c,this.log.info("Setting"+d,this)):B(this.log,"Unable to set"+d,this);return this};k.nb=function(){this.a?B(this.log,"Ignoring noFetch since the pubads service is already enabled",this):this.fa=i};k.disableInitialLoad=function(){this.a?B(this.log,"Ignoring disableInitialLoad since the pubads service is already enabled",this):this.ea=g};
k.enableSingleRequest=function(){this.isEnabled()&&!this.q?B(this.log,"Ignoring change to single request mode since the service is already enabled",this):(this.log.info("Using single request mode to fetch ads",this),this.q=g);return this.q};k.enableAsyncRendering=function(){this.isEnabled()&&!this.d?B(this.log,"Ignoring change to async-rendering mode since the service is already enabled",this):(this.log.info("Using async-rendering mode to fetch ads",this),this.d=g);return this.d};
k.Wa=function(){if(this.isEnabled()&&this.d)B(this.log,"Ignoring change to async-rendering mode since the service is already enabled",this);else{this.log.info("Using sync-rendering mode to fetch ads",this);this.d=i;for(var a=this.l(),b=0;b<a.length;++b)a[b].L=i}return!this.d};
k.refresh=function(a){if(a&&!m(a))B(this.log,"Slots to refresh must be an array.",this);else if(this.a){var b=h;if(a){for(var b=[],c=0;c<a.length;++c){var d=a[c];d instanceof O?b.push(d):B(this.log,"Slot object at position "+c+" is of incorrect type.",this)}if(!b.length){this.log.error("No valid slot ids found, refresh aborted.",this);return}}this.log.info("Refreshing ads",this);this.a.refresh(b)}else B(this.log,"The ads cannot be refreshed because the GPT implementation Javascript is not yet loaded.",
this)};
k.sa=function(a,b,c,d,f,j,o,y){if(a&&!m(a))B(this.log,"Slots to refresh must be an array.",this);else if(b&&!p(b))B(this.log,"Correlator must be a number.",this);else if(c&&!n(c))B(this.log,"Pstok must be a string.",this);else if(d&&!n(d))B(this.log,"Video IU must be a string.",this);else if(f&&!m(f))B(this.log,"Video IU sizes must be an array.",this);else if(j&&!p(j))B(this.log,"Pod number must be a number.",this);else if(o&&!p(o))B(this.log,"Pod position must be a number.",this);else if(y&&"boolean"!=
typeof y)B(this.log,"Persistent roadblocks only must be a boolean.",this);else if(this.a){var G=h;if(a){for(var G=[],s=0;s<a.length;++s){var q=a[s];q instanceof O?G.push(q):B(this.log,"Slot object at position "+s+" is of incorrect type.",this)}if(!G.length){this.log.error("No valid slot ids found, refresh aborted.",this);return}}if(f)for(s=0;s<f.length;++s){a=f[s];if(!m(a)||2!=a.length){this.log.error("Video size array must have only two values, refresh aborted.",this);return}for(q=0;q<a.length;++q)if(!p(a[q])){this.log.error("Video size array must contain only numbers, refresh aborted.",
this);return}}this.log.info("Refreshing ads",this);this.a.refresh(G,b,c,d,f,j,o,y)}else B(this.log,"The ads cannot be refreshed because the GPT implementation Javascript is not yet loaded.",this)};k.Xa=function(){this.O=g;La(this)};k.tb=function(a,b){this.O=g;this.ia=a;this.ha=b;La(this)};var La=function(a){a.O&&(a.a&&a.a.setVideoContentInformation)&&a.a.setVideoContentInformation(a.ia,a.ha)};k=Y.prototype;
k.getCorrelator=function(){return 0==this.l().length?"not_available":!this.a?"not_loaded":this.a.getCorrelator==h?"not_available":this.a.getCorrelator()};k.isAdRequestFinished=function(){return!this.a?i:this.a.isAdRequestFinished!=h?this.a.isAdRequestFinished():h};k.isSlotAPersistentRoadblock=function(a){return this.a&&this.a.isSlotAPersistentRoadblock!=h?this.a.isSlotAPersistentRoadblock(a):i};
k.collapseEmptyDivs=function(){this.D?B(this.log,"Ignoring subsequent call to set div collapse mode (already set)",this):this.isEnabled()?B(this.log,"Ignoring change to div collapse mode since the service is already enabled",this):(this.log.info("Enabling collapsing of containers when there is no ad content",this),this.D=g);return this.D};
k.clear=function(){if(!this.a)return B(this.log,"The slot contents cannot be cleared because the GPT implementation Javascript is not yet loaded.",this),i;if(this.a.clearSlotContents!=h)return this.log.info("Clearing slot contents.",this),this.a.clearSlotContents();B(this.log,"The GPT implementation does not yet support clearing slots.");return i};
k.clearNoRefreshState=function(){this.a?this.a.clearNoRefreshState!=h?(this.log.info("Clearing no_refresh state.",this),this.a.clearNoRefreshState()):B(this.log,"The GPT implementation does not yet support clearNoRefreshState"):B(this.log,"The no_refresh state cannot be cleared because the GPT implementation Javascript is not yet loaded.",this)};k.clearSlotTargeting=function(a){this.a&&r(this.a.clearSlotTargeting)&&this.a.clearSlotTargeting(a)};
k.oa=function(a,b,c){this.a&&r(this.a.addSlotTargeting)&&this.a.addSlotTargeting(a,b,c)};w("pubads",function(){var a=V(),b=a.find("publisher_ads");b||(b=new Y,a.add(b));return b});Y.prototype.clear=Y.prototype.clear;Y.prototype.clearNoRefreshState=Y.prototype.clearNoRefreshState;Y.prototype.collapseEmptyDivs=Y.prototype.collapseEmptyDivs;Y.prototype.enableAsyncRendering=Y.prototype.enableAsyncRendering;Y.prototype.enableSingleRequest=Y.prototype.enableSingleRequest;
Y.prototype.enableSyncRendering=Y.prototype.Wa;Y.prototype.enableVideoAds=Y.prototype.Xa;Y.prototype.getCorrelator=Y.prototype.getCorrelator;Y.prototype.isAdRequestFinished=Y.prototype.isAdRequestFinished;Y.prototype.isSlotAPersistentRoadblock=Y.prototype.isSlotAPersistentRoadblock;Y.prototype.noFetch=Y.prototype.nb;Y.prototype.onGoogleAdsJsLoad=Y.prototype.pb;Y.prototype.refresh=Y.prototype.refresh;Y.prototype.setTargeting=Y.prototype.da;Y.prototype.setVideoContent=Y.prototype.tb;
Y.prototype.videoRefresh=Y.prototype.sa;var Ma=/#|$/,Na=function(a,b){var c=a.search(Ma),d;a:{d=0;for(var f=b.length;0<=(d=a.indexOf(b,d))&&d<c;){var j=a.charCodeAt(d-1);if(38==j||63==j)if(j=a.charCodeAt(d+f),!j||61==j||38==j||35==j)break a;d+=f+1}d=-1}if(0>d)return h;f=a.indexOf("&",d);if(0>f||f>c)f=c;d+=b.length+1;return decodeURIComponent(a.substr(d,f-d).replace(/\+/g," "))};var Oa=function(){var a=window,b=document;if(v()._pubconsole_disable_)return i;var c;c=document.cookie.split("google_pubconsole=");if(c=2==c.length?c[1].split(";")[0]:"")if(c=c.split("|"),0<c.length&&("1"==c[0]||"0"==c[0]))return g;V();c=i;try{c=a.top.document.URL===b.URL}catch(d){}a=c?b.URL:b.referrer;return Na(a,"google_debug")!==h||Na(a,"google_console")!==h};
da(window,function(){if(Oa()){var a=document,b=a.createElement("script");b.type="text/javascript";b.src=Da()+"//publisherconsole.appspot.com/js/loader.js";b.async=g;(a=a.getElementsByTagName("script")[0])&&a.parentNode&&a.parentNode.insertBefore(b,a)}});w("disablePublisherConsole",function(){v()._pubconsole_disable_=g});var $=v().cmd;if(!$||m($)){var Pa=v().cmd=new D;$&&0<$.length&&Pa.push.apply(Pa,$)}(function(){var a=document.getElementsByTagName("script");0<a.length&&(a=a[a.length-1],a.src&&(0<=a.src.indexOf("/tag/js/gpt.js")&&a.innerHTML&&!a.googletag_executed)&&(a.googletag_executed=g,eval(a.innerHTML)))})();})()