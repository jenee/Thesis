/*1338773350,176833977*/

if (window.CavalryLogger) { CavalryLogger.start_js(["wRC12"]); }

__d("AvailableListConstants",[],function(a,b,c,d,e,f){var g={ON_AVAILABILITY_CHANGED:'buddylist/availability-changed',ON_UPDATE_ERROR:'buddylist/update-error',ON_UPDATED:'buddylist/updated',ON_CHAT_NOTIFICATION_CHANGED:'chat-notification-changed',OFFLINE:0,IDLE:1,ACTIVE:2,MOBILE:3,LEGACY_OVERLAY_OFFLINE:-1,LEGACY_OVERLAY_ONLINE:0,LEGACY_OVERLAY_IDLE:1,legacyStatusMap:{'0':2,'1':1,'-1':0,'2':3},reverseLegacyStatusMap:{0:-1,1:1,2:0,3:2}};window.AvailableListConstants=e.exports=g;},3);
__d("PresencePrivacy",["hasArrayNature","Arbiter","AsyncRequest","ChannelConstants","copyProperties","Env","JSLogger","PresenceUtil","PresencePrivacyInitialData"],function(a,b,c,d,e,f){var g=b('hasArrayNature'),h=b('Arbiter'),i=b('AsyncRequest'),j=b('ChannelConstants'),k=b('copyProperties'),l=b('Env'),m=b('JSLogger'),n=b('PresenceUtil'),o=c('PresencePrivacyInitialData'),p='/ajax/chat/privacy/settings.php',q='/ajax/chat/privacy/online_policy.php',r='/ajax/chat/privacy/visibility.php',s='friend_visibility',t='visibility',u='online_policy',v=k({},o.privacyData),w=o.visibility,x=k({},o.privacyData),y=w,z=o.onlinePolicy,aa=z,ba=[],ca=false;function da(){return m.create('blackbird');}var ea=k(new h(),{WHITELISTED:1,BLACKLISTED:-1,UNLISTED:0,ONLINE:1,OFFLINE:0,ONLINE_TO_WHITELIST:0,ONLINE_TO_BLACKLIST:1});function fa(ra){var sa;for(sa in ra){var ta=ra[sa];if(sa==l.user){da().error('set_viewer_visibility');throw new Error("Invalid to set current user's visibility");}switch(ta){case ea.WHITELISTED:case ea.BLACKLISTED:case ea.UNLISTED:break;default:da().error('set_invalid_friend_visibility',{id:sa,value:ta});throw new Error("Invalid state: "+ta);}}for(sa in ra)v[sa]=ra[sa];ea.inform('privacy-changed');}function ga(ra,sa){var ta={};ta[ra]=sa;fa(ta);}function ha(ra){switch(ra){case ea.ONLINE:case ea.OFFLINE:break;default:da().error('set_invalid_visibility',{value:ra});throw new Error("Invalid visibility: "+ra);}w=ra;ea.inform('privacy-changed');ea.inform('privacy-user-presence-changed');h.inform('chat/visibility-changed',{sender:this});}function ia(ra){switch(ra){case ea.ONLINE_TO_WHITELIST:case ea.ONLINE_TO_BLACKLIST:break;default:throw new Error("Invalid default online policy: "+ra);}z=ra;ea.inform('privacy-user-presence-changed');ea.inform('privacy-changed');}function ja(ra,sa){ca=true;ra.send();}function ka(ra,sa){ba.push({request:ra,data:sa});if(!ca){var ta=ba.shift();ja(ta.request,ta.data);}}function la(ra,sa){var ta=ra.type;if(ta===s){var ua=sa.payload.user_availabilities;if(!g(ua)){ea.inform('privacy-availability-changed',{user_availabilities:ua});for(var va in ra.settings)x[va]=ra.settings[va];}}else{if(ta===t){y=ra.visibility;}else if(ta===u)aa=ra.online_policy;ea.inform('privacy-user-presence-response');}da().log('set_update_response',{data:ra,response:sa});}function ma(ra,sa){if(w!==y)ha(y);if(z!==aa)ia(aa);k(v,x);ea.inform('privacy-changed');ba=[];da().log('set_error_response',{data:ra,response:sa});}function na(ra){ca=false;if(ba.length>0){var sa=ba.shift();ja(sa.request,sa.data);}}function oa(ra,sa){if(n!=null){var ta=ra.getData();ta.window_id=n.getSessionID();ra.setData(ta);}ra.setHandler(la.bind(this,sa)).setErrorHandler(ma.bind(this,sa)).setTransportErrorHandler(ma.bind(this,sa)).setFinallyHandler(na.bind(this)).setAllowCrossPageTransition(true);return ra;}function pa(ra,sa,ta){return oa(new i(ra).setData(sa),ta);}function qa(ra,sa){var ta=sa.obj;if(ta.viewer_id!=l.user){da().error('invalid_viewer_for_channel_message',{type:ra,data:sa});throw new Error("Viewer got from the channel is not the real viewer");}if(ta.window_id===n.getSessionID())return;var ua=ta.data;if(ta.event=='access_control_entry'){ua.target_ids.forEach(function(wa){ga(wa,ua.setting);x[wa]=ua.setting;});}else{if(ta.event=='visibility_update'){var va=!!ua.visibility?ea.ONLINE:ea.OFFLINE;ha(va);y=va;}else if(ta.event=='online_policy_update'){ia(ua.online_policy);aa=ua.online_policy;}ea.inform('privacy-user-presence-response');}da().log('channel_message_received',{data:sa.obj});}k(ea,{WHITELISTED:1,BLACKLISTED:-1,UNLISTED:0,ONLINE:1,OFFLINE:0,ONLINE_TO_WHITELIST:0,ONLINE_TO_BLACKLIST:1,init:function(ra,sa,ta){},setVisibility:function(ra){y=w;ha(ra);var sa={visibility:ra},ta={type:t,visibility:ra},ua=pa(r,sa,ta);ka(ua,ta);da().log('set_visibility',{data:sa});return ra;},getVisibility:function(){return w;},setOnlinePolicy:function(ra){aa=z;ia(ra);var sa={online_policy:ra},ta={type:u,online_policy:ra},ua=pa(q,sa,ta);ka(ua,ta);da().log('set_online_policy',{data:sa});return ra;},getOnlinePolicy:function(){return z;},getFriendVisibility:function(ra){return v[ra]||ea.UNLISTED;},allows:function(ra){if(this.getVisibility()===ea.OFFLINE)return false;var sa=this.getOnlinePolicy();return sa===ea.ONLINE_TO_WHITELIST?v[ra]==ea.WHITELISTED:v[ra]!=ea.BLACKLISTED;},setFriendsVisibility:function(ra,sa){if(ra.length>0){var ta={};for(var ua=0;ua<ra.length;ua++){var va=ra[ua];x[va]=v[va];ta[va]=sa;}fa(ta);var wa=sa;if(wa==ea.UNLISTED)wa=x[ra[0]];var xa={users:ra,setting:sa,setting_type:wa},ya={type:s,settings:ta},za=pa(p,xa,ya);ka(za,ya);da().log('set_friend_visibility',{data:xa});}return sa;},setFriendVisibilityMap:function(ra,sa){for(var ta in ra)x[ta]=v[ta];fa(ra);var ua={type:s,settings:ra};ka(oa(sa,ua),ua);da().log('set_friend_visibility_from_map',{data:ra});},allow:function(ra){if(this.allows(ra)){da().error('allow_already_allowed');throw new Error("allow() should only be called for users that "+"are not already allowed");}if(this.getVisibility()===ea.OFFLINE){da().error('allow_called_while_offline');throw new Error("allow() should only be called when the user is already online");}var sa=this.getOnlinePolicy()===ea.ONLINE_TO_WHITELIST?ea.WHITELISTED:ea.UNLISTED;return this.setFriendsVisibility([ra],sa);},disallow:function(ra){if(!this.allows(ra)){da().error('disallow_already_disallowed');throw new Error("disallow() should only be called for users that "+"are not already disallowed");}if(this.getVisibility()===ea.OFFLINE){da().error('disallow_called_while_offline');throw new Error("disallow() should only be called when the user is already online");}var sa=this.getOnlinePolicy()===ea.ONLINE_TO_BLACKLIST?ea.BLACKLISTED:ea.UNLISTED;return this.setFriendsVisibility([ra],sa);},getBlacklist:function(){var ra=[];for(var sa in v)if(v[sa]===ea.BLACKLISTED)ra.push(sa);return ra;},getWhitelist:function(){var ra=[];for(var sa in v)if(v[sa]===ea.WHITELISTED)ra.push(sa);return ra;},getMapForTest:function(){return v;},setMapForTest:function(ra){v=ra;}});ea.inform('privacy-changed');ea.inform('privacy-user-presence-changed');da().log('initialized',{visibility:w,policy:z});h.subscribe(j.getArbiterType('privacy_changed'),qa.bind(this));h.subscribe(j.ON_CONFIG,function(ra,sa){var ta=sa.getConfig('visibility',null);if(ta!==null&&typeof(ta)!=='undefined'){var ua=ta?ea.ONLINE:ea.OFFLINE;ha(ua);da().log('config_visibility',{vis:ua});}}.bind(this));a.PresencePrivacy=e.exports=ea;},3);
__d("Chat",["Arbiter","AsyncSignal","JSLogger","PresencePrivacy"],function(a,b,c,d,e,f){var g=b('Arbiter'),h=b('AsyncSignal'),i=b('JSLogger'),j=b('PresencePrivacy');function k(o,p){if(p&&p=='ordered_list'||p=='more_online_friends'||p=='online_friends'||p=='typeahead'){var q={target:o,source:p};new h('/ajax/chat/ct.php',q).send();}}var l={buddyListNub:'buddylist-nub/initialized',sidebar:'sidebar/initialized'};function m(o,p){g.subscribe(l[o],function(event,q){p(q);});}var n={openTab:function(o,p,q,r){if(window.External&&window.External.Chat&&window.External.Chat.openWindow)window.External.Chat.openWindow(o);k(o,r);d(['MercuryThreads'],function(s){if(!q||q=='friend'){var t=s.getCanonicalThreadToUser(o);g.inform('chat/open-tab',{thread_id:t.thread_id});}});},openBuddyList:function(){m('buddyListNub',function(o){o.show();m('sidebar',function(p){p.enable();});});},closeBuddyList:function(){m('buddyListNub',function(o){o.hide();});},toggleSidebar:function(){m('sidebar',function(o){o.toggle();});},goOnline:function(o){d(['ChatVisibility'],function(p){p.goOnline(o);});},isOnline:function(){var o=null;d(['ChatVisibility'],function(p){o=p;});return o&&o.isOnline();}};a.Chat=e.exports=n;},3);
__d("ChatVisibility",["ChatConfig","JSLogger","PresencePrivacy"],function(a,b,c,d,e,f){var g=b('ChatConfig'),h=b('JSLogger'),i=b('PresencePrivacy'),j={isOnline:function(){return i.getVisibility()===i.ONLINE;},goOnline:function(k){if(i.getVisibility()===i.OFFLINE){h.create('blackbird').log('chat_go_online');i.setVisibility(i.ONLINE);}k&&k();},goOffline:function(k){if(i.getVisibility()===i.ONLINE){h.create('blackbird').log('chat_go_offline');i.setVisibility(i.OFFLINE);}k&&k();},toggleVisibility:function(){if(j.isOnline()){j.goOffline();}else j.goOnline();}};a.ChatVisibility=e.exports=j;},3);
__d("ServerTime",["PresenceInitialData"],function(a,b,c,d,e,f){var g=c('PresenceInitialData'),h;function i(k){h=Date.now()-k;}i(g.serverTime);var j={get:function(){return Date.now()-h;},getSkew:function(){return h;},update:function(k){i(k);}};e.exports=j;});
__d("AvailableList",["function-extensions","Arbiter","ArbiterMixin","AsyncRequest","AvailableListConstants","ChannelConnection","ChannelConstants","Chat","ChatConfig","ChatVisibility","Class","Env","JSLogger","Poller","PresencePrivacy","PresenceUtil","ServerTime","ShortProfiles","UserActivity","copyProperties","createObjectFrom","debounceAcrossTransitions","AvailableListInitialData"],function(a,b,c,d,e,f){b('function-extensions');var g=b('Arbiter'),h=b('ArbiterMixin'),i=b('AsyncRequest'),j=b('AvailableListConstants'),k=b('ChannelConnection'),l=b('ChannelConstants'),m=b('Chat'),n=b('ChatConfig'),o=b('ChatVisibility'),p=b('Class'),q=b('Env'),r=b('JSLogger'),s=b('Poller'),t=b('PresencePrivacy'),u=b('PresenceUtil'),v=b('ServerTime'),w=b('ShortProfiles'),x=b('UserActivity'),y=b('copyProperties'),z=b('createObjectFrom'),aa=b('debounceAcrossTransitions'),ba=c('AvailableListInitialData'),ca=5,da=60000,ea='/ajax/chat/buddy_list.php',fa=5000,ga=1800000,ha=.005,ia=0,ja=0,ka=false,la=ba.pollInterval,ma=ba.lazyPollInterval,na=ba.lazyThreshold,oa=0,pa=Date.now(),qa=0,ra=false,sa={},ta=false,ua={},va=null,wa={},xa={},ya=r.create('available_list'),za=y({},j,h);za.subscribe([j.ON_AVAILABILITY_CHANGED,j.ON_UPDATE_ERROR,j.ON_UPDATED],function(sb,tb){g.inform(sb,tb);});function ab(sb){var tb=sb||x.isActive(na);return o.isOnline()?(tb?la:ma):null;}function bb(){za.inform(j.ON_AVAILABILITY_CHANGED);}var cb=aa(bb,0);function db(sb,tb,ub,vb){if(sb==q.user)return;switch(tb){case j.OFFLINE:case j.IDLE:case j.ACTIVE:case j.MOBILE:break;default:return;}var wb=za.get(sb)!=tb;if(ub){wa[sb]=v.get();xa[sb]=vb;}sa[sb]=tb;if(wb){ia++;cb();}}function eb(sb){qa=Date.now();ua=z(sb);ia++;cb();}function fb(){if(ra)za.inform(j.ON_UPDATED,za);}function gb(sb){if(u.checkMaintenanceError(sb))return;ja++;ka=false;if(ja>=ca)za.inform(j.ON_UPDATE_ERROR);}function hb(sb){var tb=sb.getPayload(),ub=tb.buddy_list;if(!ub){gb(sb);return;}v.update(tb.time);oa=v.get();ja=0;ka=false;if(ub.mobile_friends!=null)eb(ub.mobile_friends);var vb=ub.userInfos;if(vb)w.setMulti(vb);nb();ta=ub.userIsIdle;var wb=ub.nowAvailableList;wb&&lb(wb);if(ub.chatNotif!==undefined){va=ub.chatNotif;za.inform(j.ON_CHAT_NOTIFICATION_CHANGED,va);}mb();fb();cb();}function ib(sb){if(k.isShutdown()||!o.isOnline()){za._poller.stop();return;}pa=Date.now();var tb=false;if(Date.now()-qa>ga)tb=true;ka=true;var ub=w.getCachedProfileIDs();sb.setHandler(hb).setErrorHandler(gb).setOption('suppressErrorAlerts',true).setOption('retries',1).setData({user:q.user,available_user_info_ids:ub,fetch_mobile:tb}).setURI(ea).setAllowCrossPageTransition(true);}function jb(sb){var tb=sb.payload.availability||{};for(var ub in tb)db(ub,tb[ub],true,'mercury_tabs');}function kb(sb){var tb=za.getDebugInfo(sb),ub=(tb.presence==j.ACTIVE),vb=new i('/ajax/mercury/tabs_presence.php').setData({target_id:sb,to_online:ub,presence_source:tb.overlaySource,presence_time:tb.overlayTime}).setHandler(jb).setErrorHandler(bagofholding).setAllowCrossPageTransition(true).send();}function lb(sb){for(var tb in sb)db(tb,sb[tb].a,false,null);ra=true;}function mb(sb){var tb=ab(sb);ya.debug('update_poller',tb);za._poller&&za._poller.setTimePeriod(tb);}function nb(){ra=false;sa={};xa={};wa={};ia++;}function ob(){nb();pa=0;qa=0;ta=false;va=null;ua={};bb();}function pb(){mb();if(o.isOnline()){za.update();}else ob();}function qb(){mb();if(k.disconnected()){ob();}else if(!ra)za.update();}function rb(sb,tb){tb.chat_config=n.getDebugInfo();tb.available_list_debug_info={};za.getAvailableIDs().forEach(function(ub){tb.available_list_debug_info[ub]=za.getDebugInfo(ub);});tb.available_list_poll_interval=za._poller&&za._poller.getTimePeriod();}y(za,{get:function(sb){if(sb==q.user)return o.isOnline()?j.ACTIVE:j.OFFLINE;var tb=j.OFFLINE;if(sb in sa)tb=sa[sb];if(!t.allows(sb))tb=j.OFFLINE;if(tb==j.OFFLINE)if(ua[sb])tb=j.MOBILE;return tb;},updateForID:function(sb){kb(sb);},getWebChatNotification:function(){return va;},isUserIdle:function(){return ta;},isReady:function(){return ra;},set:function(sb,tb,ub){db(sb,tb,true,null,ub);},update:function(){if(Date.now()-pa<fa){!ka&&fb.defer();return;}za._poller&&za._poller.requestNow();},getRev:function(){return ia;},isIdle:function(sb){return za.get(sb)==j.IDLE;},getOnlineIDs:function(){var sb,tb=[];for(sb in sa)if(za.get(sb)===j.ACTIVE)tb.push(sb);return tb;},getAvailableIDs:function(){var sb=za.getOnlineIDs(),tb;for(tb in ua){if(sa[tb])continue;sb.push(tb);}return sb;},getOnlineCount:function(){return za.getOnlineIDs().length;},getDebugInfo:function(sb){var tb;if(window.ShortProfiles){var ub=w.getNow(sb);if(ub)tb=ub.name;}return {id:sb,presence:sa[sb],overlaySource:xa[sb],overlayTime:wa[sb],overlaySource:xa[sb],mobile:ua[sb],name:tb};}});oa=ba.updateTime;lb(ba.availableList);if(ba.mobileFriends)eb(ba.mobileFriends);va=ba.chatNotif;za._poller=new s(ab(),ib,true);mb(true);g.subscribe(r.DUMP_EVENT,rb);x.subscribe(function(sb,tb){if(tb.idleness>la){ya.debug('update_activity');za.update();}});t.subscribe('privacy-changed',bb);t.subscribe('privacy-availability-changed',function(sb,tb){for(var ub in tb.user_availabilities)this.set(ub,tb.user_availabilities[ub]);}.bind(za));t.subscribe('privacy-user-presence-response',za.update);k.subscribe([k.CONNECTED,k.RECONNECTING,k.SHUTDOWN,k.MUTE_WARNING,k.UNMUTE_WARNING],qb);g.subscribe(l.getArbiterType('buddylist_overlay'),function(sb,tb){var ub=tb.obj.overlay;for(var vb in ub)za.set(vb,ub[vb].a,ub[vb].s||'channel');});a.AvailableList=e.exports=za;});
__d("ChatConfig",["copyProperties","ChatConfigInitialData"],function(a,b,c,d,e,f){var g=c('ChatConfigInitialData'),h=b('copyProperties'),i={},j={get:function(k,l){return k in i?i[k]:l;},set:function(k){if(arguments.length>1){var l={};l[k]=arguments[1];k=l;}h(i,k);},getDebugInfo:function(){return i;}};j.set(g);e.exports=j;});
__d("InitialChatUserInfosLoader",["InitialChatUserInfos"],function(a,b,c,d,e,f){e.exports=c('InitialChatUserInfos');});
__d("ShortProfiles",["ArbiterMixin","AsyncLoader","AsyncRequest","Env","JSLogger","copyProperties"],function(a,b,c,d,e,f){var g=b('ArbiterMixin'),h=b('AsyncLoader'),i=b('AsyncRequest'),j=b('Env'),k=b('JSLogger'),l=b('copyProperties'),m='/ajax/chat/user_info.php',n='/ajax/chat/user_info_all.php',o=new h(m,'profiles'),p=false,q=k.create('short_profiles');function r(){if(!p){q.log('fetch_all');p=true;new i(n).setData({viewer:j.user}).setHandler(function(u){o.set(u.payload);t.inform('updated');}).setAllowCrossPageTransition(true).setMethod('GET').setReadOnly(true).send();}}function s(u){return JSON.parse(JSON.stringify(u));}var t={};l(t,g,{get:function(u,v){this.getMulti([u],function(w){v(w[u],u);});},getMulti:function(u,v){function w(x){v(s(x));}o.get(u,w);},getNow:function(u){return s(o.getNow(u)||null);},getCachedProfileIDs:function(){return o.getCachedKeys();},hasAll:function(){return p;},fetchAll:function(){r();},set:function(u,v){var w={};w[u]=v;this.setMulti(w);},setMulti:function(u){o.set(s(u));}});d(['InitialChatUserInfosLoader'],function(u){t.setMulti(u);});e.exports=t;});
__d("PresenceUtil",["Cookie","Env","math-extensions","tx"],function(a,b,c,d,e,f){var g=b('Cookie'),h=b('Env'),i=b('math-extensions'),j=b('tx'),k=i.rand32()+1;a.PresenceUtil=e.exports={checkMaintenanceError:function(l){if(l.getError()==1356007)return true;return false;},getErrorDescription:function(l){var m=l.getError(),n=l.getErrorDescription();if(!n)n="An error occurred.";if(m==1357001)n="Your session has timed out. Please log in.";return n;},getSessionID:function(){return k;},hasUserCookie:function(){return h.user===g.get('c_user');}};},3);
__d("PresenceCookieManager",["Cookie","Dcode","ErrorUtils","Env","JSLogger","PresenceUtil","URI","PresenceInitialData"],function(a,b,c,d,e,f){var g=b('Cookie'),h=b('Dcode'),i=b('ErrorUtils'),j=b('Env'),k=b('JSLogger'),l=b('PresenceUtil'),m=b('URI'),n=c('PresenceInitialData'),o=n.cookieVersion,p=n.dictEncode,q='presence',r={},s=null,t=null,u=k.create('presence_cookie');function v(){try{var z=g.get(q);if(s!==z){s=z;t=null;if(z&&z.charAt(0)=='E')z=h.decode(z.substring(1));if(z)t=JSON.parse(z);}if(t&&(!t.user||t.user===j.user))return t;}catch(y){u.warn('getcookie_error');}return null;}function w(){return parseInt(new Date().getTime()/1000,10);}var x={register:function(y,z){r[y]=z;},store:function(){var y=v();if(y&&y.v&&o<y.v)return;var z={v:o,time:w(),user:j.user};for(var aa in r)z[aa]=i.applyWithGuard(r[aa],r,[y&&y[aa]],function(ea){ea.presence_subcookie=aa;});var ba=JSON.stringify(z);if(p)ba='E'+h.encode(ba);if(l.hasUserCookie()){var ca=ba.length;if(ca>1024)u.warn('big_cookie',ca);var da=m.getRequestURI(false).isSecure()&&!!g.get('csm');g.set(q,ba,null,null,da);}},clear:function(){g.clear(q);},getSubCookie:function(y){var z=v();if(!z)return null;return z[y];}};e.exports=x;});
__d("PresenceState",["Arbiter","ErrorUtils","JSLogger","math-extensions","PresenceCookieManager","copyProperties","debounceAcrossTransitions","setIntervalAcrossTransitions","PresenceInitialData"],function(a,b,c,d,e,f){var g=b('Arbiter'),h=b('ErrorUtils'),i=b('JSLogger'),j=b('math-extensions'),k=b('PresenceCookieManager'),l=b('copyProperties'),m=b('debounceAcrossTransitions'),n=b('setIntervalAcrossTransitions'),o=c('PresenceInitialData'),p=o.cookiePollInterval||2000,q=[],r=[],s=null,t=null,u=0,v=null,w=0,x=['sb2','t2','lm2','uct2','tr','tw','at'],y=i.create('presence_state');function z(){return k.getSubCookie('state');}function aa(){u=Date.now();k.store();da(t);}var ba=m(aa,0);function ca(ha){var ia={};if(ha){x.forEach(function(la){ia[la]=ha[la];});if(u<ha.ut)y.error('new_cookie',{cookie_time:ha.ut,local_time:u});}ia.ut=u;for(var ja=0,ka=q.length;ja<ka;ja++)h.applyWithGuard(q[ja],null,[ia]);t=ia;return t;}function da(ha){w++;u=j.verifyNumber(ha.ut);if(!s)s=n(ga,p);t=ha;if(v===null)v=ha;for(var ia=0,ja=r.length;ia<ja;ia++)h.applyWithGuard(r[ia],null,[ha]);w--;}function ea(ha){if(ha&&ha.ut)if(u<ha.ut){return true;}else if(ha.ut<u)y.error('old_cookie',{cookie_time:ha.ut,local_time:u});return false;}function fa(){var ha=z();if(ea(ha))t=ha;return t;}function ga(){var ha=z();if(ea(ha))da(ha);}k.register('state',ca);g.subscribe(i.DUMP_EVENT,function(ha,ia){ia.presence_state={initial:l({},v),state:l({},t),update_time:u,sync_paused:w,poll_time:p};});(function(){var ha=fa();if(ha){da(ha);}else{y.debug('no_cookie_initial');da(ca());return;}})();a.PresenceState=e.exports={doSync:function(ha){if(w)return;if(ha){aa();}else ba();},registerStateStorer:function(ha){q.push(ha);},registerStateLoader:function(ha){r.push(ha);},get:function(){return fa();},getInitial:function(){return v;}};},3);
function LiveMessageReceiver(a){this.eventName=a;this.subs=null;this.handler=bagofholding;this.shutdownHandler=null;this.registered=false;this.appId=1;}LiveMessageReceiver.getAppMessageType=function(a,b){return 'live_message/'+a+':'+b;};LiveMessageReceiver.prototype.setAppId=function(a){this.appId=a;return this;};LiveMessageReceiver.prototype.setHandler=function(a){this.handler=a;this._dirty();return this;};LiveMessageReceiver.prototype.setRestartHandler=function(){};LiveMessageReceiver.prototype.setShutdownHandler=function(a){this.shutdownHandler=a.shield();this._dirty();return this;};LiveMessageReceiver.prototype._dirty=function(){if(this.registered){this.unregister();this.register();}};LiveMessageReceiver.prototype.register=function(){var a=function(c,d){return this.handler(d);}.bind(this),b=LiveMessageReceiver.getAppMessageType(this.appId,this.eventName);this.subs={};this.subs.main=Arbiter.subscribe(b,a);if(this.shutdownHandler)this.subs.shut=Arbiter.subscribe(ChannelConstants.ON_SHUTDOWN,this.shutdownHandler);this.registered=true;return this;};LiveMessageReceiver.prototype.unregister=function(){if(!this.subs)return this;for(var a in this.subs)if(this.subs[a])this.subs[a].unsubscribe();this.subs=null;this.registered=false;return this;};LiveMessageReceiver.route=function(a){var b=function(c){var d=LiveMessageReceiver.getAppMessageType(a.app_id,a.event_name);Arbiter.inform(d,c,Arbiter.BEHAVIOR_PERSISTENT);};if(a.hasCapture){new AsyncRequest().setHandler(function(c){b(c.getPayload());}).setAllowCrossPageTransition(true).handleResponse(a.response);}else b(a.response);};var init_live_message_receive=window.init_live_message_receive||function(){init_live_message_receive=bagofholding;Arbiter.subscribe(ChannelConstants.getArbiterType('app_msg'),function(a,b){if(b.obj.event_name=='beep_event'){Bootloader.loadComponents('beeper',function(){Beeper.ensureInitialized();LiveMessageReceiver.route(b.obj);});}else LiveMessageReceiver.route(b.obj);});};
__d("GroupChatController",["Arbiter","Chat","ChatController","ChatVisibility","CSS","DOM","PageTransitions"],function(a,b,c,d,e,f){var g=b('Arbiter'),h=b('Chat'),i=b('ChatController'),j=b('ChatVisibility'),k=b('CSS'),l=b('DOM'),m=b('PageTransitions');function n(o,p,q){_goOnlineText=l.find(o,'.fbGroupChatGoOnline');_chatWithGroupText=l.find(o,'.fbGroupChatOpenTab');function r(){if(j.isOnline()){k.hide(_goOnlineText);k.show(_chatWithGroupText);}else{k.hide(_chatWithGroupText);k.show(_goOnlineText);}}_visibilitySubscription=g.subscribe('chat/visibility-changed',r);m.registerHandler(g.unsubscribe.bind(g,_visibilitySubscription));Event.listen(o,'click',function(){i.raiseGroupTab(p);});r();}e.exports=n;});
function PresenceIndicator(){}copy_properties(PresenceIndicator.prototype,{init:function(a,b,c){this._id=a;this._firstname=b;this._tooltip=c;this._image=DOM.scry(this._tooltip,'i')[0];this._previousAvail=null;this._jslog=JSLogger.create('presence_indicator');requireLazy(['ChatVisibility'],function(e){this._jslog.log('vis_init',e.isOnline());this._chatVisibility=e;this._updateVisibility();}.bind(this));this._subscriptions=[Arbiter.subscribe([AvailableListConstants.ON_AVAILABILITY_CHANGED],this._updateAvailability.bind(this)),Arbiter.subscribe(['chat/visibility-changed'],this._updateVisibility.bind(this))];this._updateAvailability.bind(this).defer();var d=Event.listen(this._tooltip,'click',function(){requireLazy(['AvailableList'],function(e){if(this._previousAvail!=AvailableListConstants.OFFLINE)Chat.openTab(this._id);}.bind(this));}.bind(this));onleaveRegister(function(){d.remove();while(this._subscriptions.length)Arbiter.unsubscribe(this._subscriptions.pop());}.bind(this));},_updateAvailability:function(){requireLazy(['AvailableList','ChatConfig'],function(a,b){if(!a.isReady())return;var c,d,e=a.get(this._id);if(e===this._previousAvail)return;this._previousAvail=e;switch(e){case AvailableListConstants.OFFLINE:c=tx._("{name} is offline",{name:this._firstname});d='offline';break;case AvailableListConstants.IDLE:c=tx._("{name} is idle",{name:this._firstname});d='idle';break;case AvailableListConstants.ACTIVE:c=tx._("{name} is online",{name:this._firstname});d='online';break;case AvailableListConstants.MOBILE:c=tx._("{name} is available on mobile",{name:this._firstname});d='mobile';break;default:throw new Error('Invalid availability');}TooltipLink.setTooltipText(this._tooltip,c);CSS.setClass(this._image,d);}.bind(this));},_updateVisibility:function(){if(this._chatVisibility.isOnline()){CSS.show(this._tooltip);}else CSS.hide(this._tooltip);}});