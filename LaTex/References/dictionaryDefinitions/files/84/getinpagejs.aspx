function isSilverlightVersionInstalled(version)
{
    if (version == undefined)
        version = null;
        
    var isVersionSupported = false;
    var container = null;

    try
    {
        var control = null;
        var tryNS = false;

        if (window.ActiveXObject)
        {
            try
            {
                control = new ActiveXObject('AgControl.AgControl');
                if (version === null)
                {
                    isVersionSupported = true;
                }
                else if (control.IsVersionSupported(version))
                {
                    isVersionSupported = true;
                }
                control = null;
            }
            catch (e)
            {
                tryNS = true;
            }
        }
        else
        {
            tryNS = true;
        }
        if (tryNS)
        {
            var plugin = navigator.plugins["Silverlight Plug-In"];
            if (plugin)
            {
                if (version === null)
                {
                    isVersionSupported = true;
                }
                else
                {
                    var actualVer = plugin.description;
                    if (actualVer === "1.0.30226.2")
                        actualVer = "2.0.30226.2";
                    var actualVerArray = actualVer.split(".");
                    while (actualVerArray.length > 3)
                    {
                        actualVerArray.pop();
                    }
                    while (actualVerArray.length < 4)
                    {
                        actualVerArray.push(0);
                    }
                    var reqVerArray = version.split(".");
                    while (reqVerArray.length > 4)
                    {
                        reqVerArray.pop();
                    }

                    var requiredVersionPart;
                    var actualVersionPart;
                    var index = 0;


                    do
                    {
                        requiredVersionPart = parseInt(reqVerArray[index]);
                        actualVersionPart = parseInt(actualVerArray[index]);
                        index++;
                    }
                    while (index < reqVerArray.length && requiredVersionPart === actualVersionPart);

                    if (requiredVersionPart <= actualVersionPart && !isNaN(requiredVersionPart))
                    {
                        isVersionSupported = true;
                    }
                }
            }
        }
    }
    catch (e)
    {
        isVersionSupported = false;
    }
    
    return isVersionSupported;
};
function isSilverlightInstalled(){
	var found;
	for (var major = 4; major >= 1; major--){
		for(var minor = 9; minor >= 0; minor--){
			var version = major + "." + minor;
			if (isSilverlightVersionInstalled(version)){return true;}
		}
	}
	return false;
};try {
    // find url the page is running on
    window.parentIsPermitted = false;
    window.DVCurWin = window;
    try {
        for (i = 0; i <= 10; i++) {
            if ((window.DVCurWin.parent != null) && (window.DVCurWin.parent != window.DVCurWin)) {
                var loc = window.DVCurWin.parent.location.toString();
                var x = loc.length;
                if (x > 0) {
                    window.DVCurWin = window.DVCurWin.parent;
                    window.parentIsPermitted = true;
                }
                else {
                    window.parentIsPermitted = false;
                    break;
                }
            }
            else {
                if (i == 0) { window.parentIsPermitted = true; }
                break;
            }
        }
    }
    catch (e)
    { window.parentIsPermitted = false; }

    if (window.DVCurWin.document.referrer.length == 0) {
        window.DVURL = window.DVCurWin.location;
    }
    else {
        if (window.parentIsPermitted) {
            window.DVURL = window.DVCurWin.location;
        }
        else {
            window.DVURL = window.DVCurWin.document.referrer;
        }
    }

    window.DVParam=escape(window.DVURL);
}
catch (ex) {}function isSecure(){try {return window.location.protocol == 'https:';} catch (err){return false;}}
function icSecureURL(url){try {if (url !=null && url != undefined && typeof(url) == "string" && url.substring(0,5) == "http:" && isSecure()){return "https:" + url.substring(5);}return url;}catch (err){return url;}}
function icAppendIfLength(maxLength, s1, s2){try{var s = s1 + s2;if (s.length <= maxLength){return s;}return s1;}catch(err){return s1;}}
function icIsIframed(){try {if (window!=window.top){return true;}else{return false;}} catch(err){return true;}}
function icGetEncReferrer(){try {return encodeURIComponent(document.referrer);}catch(err){return "";}}
function icGetEncReferrerDomain(){try {var urlPReg = /\b(https?|ftp):\/\/([\-A-Z0-9.]+)(\/[\-A-Z0-9+&@#\/%=~_|!:,.;]*)?(\?[A-Z0-9+&@#\/%=~_|!:,.;]*)?/ig;if (document.referrer != null && document.referrer != undefined && icIsIframed()){var rr = urlPReg.exec(document.referrer.toString());if (rr != null && rr.length >= 3){return encodeURIComponent(rr[2]);}};if (document.location != null && document.location.href != null){var lr = urlPReg.exec(document.location.href.toString());if (lr != null && lr.length >= 3){return encodeURIComponent(lr[2]);}};return "";}catch(err){return "";}}
var IcUHData354245 = IcUHData354245 ? IcUHData354245 : new Object();
function icAddAdditionalParams(r){try{r = icAppendIfLength(2048,r,(icIsIframed()?'&isif=t':'&isif=f'));r = icAppendIfLength(2048, r, '&rurld='+icGetEncReferrerDomain());r = icAppendIfLength(2048, r, (isSilverlightInstalled() ? '&sl=true' : '&sl=false'));r = icAppendIfLength(2048, r, (window.DVParam?'&dvp='+window.DVParam:''));r = icAppendIfLength(2048, r, IcUHData354245.Dt?('&uh='+IcUHData354245.Dt()):'');r = icAppendIfLength(2048, r, '&rurl='+icGetEncReferrer());return r;}catch(err){return r;}}document.write('<scr'+'ipt language="javascript" type="text/javascript" src="'+icSecureURL(icAddAdditionalParams("http://a1.interclick.com/getInPageJSProcess.aspx?a=51&b=52913&cid=634683689697189538"))+'"></scr'+'ipt>');