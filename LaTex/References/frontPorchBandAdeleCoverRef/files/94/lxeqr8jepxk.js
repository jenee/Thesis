/*1336802065,176820405*/

if (window.CavalryLogger) { CavalryLogger.start_js(["SllaK"]); }

function NegativeNotif(a,b){copy_properties(this,b);this.owner=a;this.xLink=DOM.find(this.obj,'.notif_x');this.confirmingMsg=DOM.find(this.obj,'.confirmingMsg');this.userXClicked=false;this.userUnsubscribed=false;Event.listen(this.xLink,'click',this.xClick.bind(this));}copy_properties(NegativeNotif.prototype,{FADE_AWAY_DURATION:2500,xClick:function(event){this._activateX();var a=this.xLink.getAttribute('data-gt'),b=a?{gt:JSON.parse(a)}:{};user_action('click',this.xLink,event,null,b);return false;},restore:function(){if(this.owner.notifXList.newNotifExist(this.id)){this.owner.notifXList.resumeInsert(this.id);}else this.owner.notifXList.removeNotif(this.id);CSS.removeClass(this.obj,'negativeActions');},reset:function(){if(this.userXClicked&&!this.userUnsubscribed){this.userXClicked=false;this.restore();}},onTurnedOff:function(){this.userUnsubscribed=true;CSS.hide(this.confirmingMsg);},onUndid:function(){this.userXClicked=false;this.userUnsubscribed=false;this.restore();CSS.show(this.confirmingMsg);DOM.remove(DOM.find(this.obj,'.confirmedMsg'));},onMarkedSpam:function(){DOM.remove(DOM.find(this.obj,'.confirmedMsg'));this._fadeAway(DOM.find(this.obj,'.spamMsg'));},onFirstReceiptYes:function(){this._hideFirstReceiptDiv();this._fadeAway(DOM.find(this.obj,'.firstConfirmedMsg'));},onFirstReceiptNo:function(){this._hideFirstReceiptDiv();this._activateX();CSS.hide(this.confirmingMsg);new AsyncRequest().setURI('/ajax/notifications/negative_req.php').setData({request_type:'turn_off',notification_id:this.id}).send();},_activateX:function(){CSS.addClass(this.obj,'negativeActions');this.userXClicked=true;this.owner.notifXList.userXClick(this.id);},_hideFirstReceiptDiv:function(){CSS.hide(DOM.find(this.obj,'.first_receipt_div'));},_fadeAway:function(a){animation(a).from('backgroundColor','#FFF9D7').to('backgroundColor','#FFFFFF').duration(this.FADE_AWAY_DURATION).hide().go();}});