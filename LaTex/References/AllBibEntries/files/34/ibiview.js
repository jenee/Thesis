
﻿function _loadAux(){try{if(self.IBPartner){var go=IBPartner.Go;var _ib_id1=IBPartner.Id1;var _ib_xid=IBPartner.Xid;var _ib_ida=IBPartner.Ida;var _ib_pid=IBPartner.Pid;var bqzmisa='';}else{var go=(self._ibgo&&self._ibgo!=='${SELLER_LINE_ITEM_CODE}')?_ibgo:'';var bqzmisa=(self._ibisb&&self._ibisb!=='')?_ibisb:'';var _ib_id1='';var _ib_xid='';var _ib_ida='';var _ib_pid='';}
if(go!==''&&go!=='iblx'&&go!=='ibcx'){var s=window.document.createElement("script");s.setAttribute('type','text/javascript');s.setAttribute('src','https://ib.mookie1.com/at.js?sessionid=b37e51cf-bc52-4995-9a77-5d66f73f281b&go='+go+'&xid='+_ib_xid+'&ida='+_ib_ida+'&sb='+bqzmisa+'&osid=3155f251-a726-445e-b4a4-597536a31c45'+'&pid='+_ib_pid+'&id1='+_ib_id1);if(s.readyState){s.onreadystatechange=function(){if(s.readyState==="loaded"||s.readyState==="complete"){s.onreadystatechange=null;_TmfFnJOT.ProcessTags();}};}else{s.onload=function(){_TmfFnJOT.ProcessTags();};}
window.document.getElementsByTagName("head")[0].appendChild(s);}}catch(Error){}}
function _ib_pv(){try{_loadAux();}catch(Error){}}
_ib_pv();function ViewSetup(){}
function ViewOrigin(){}
ViewOrigin.prototype.Timestamp='6/4/2012 8:18:43 PM';ViewOrigin.prototype.Name='iBehavior.Interactive.Web.Templates.ViewSetup.min.js';ViewOrigin.prototype.Id='3155f251-a726-445e-b4a4-597536a31c45';ViewOrigin.prototype.HostPage='11662174324@x71';