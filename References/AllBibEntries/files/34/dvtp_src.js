function dv_GetParam(url, name) {
    name = name.replace(/[\[]/, "\\\[").replace(/[\]]/, "\\\]");
    var regexS = "[\\?&]" + name + "=([^&#]*)";
    var regex = new RegExp(regexS);
    var results = regex.exec(url);
    if (results == null)
        return null;
    else
        return results[1];
}

function dv_Contains(array,obj) {
    var i = array.length;
    while (i--) {
        if (array[i] === obj) {
            return true;
        }
    }
    return false;
}



function dv_createIframe() {
    var iframe;
    if (document.createElement && (iframe = document.createElement('iframe'))) {
        iframe.name = iframe.id = Math.floor((Math.random() + "") * 1000000000000).toString();
        iframe.width = 0;
        iframe.height = 0;
        iframe.style.display = 'none';
        iframe.src = 'about:blank';
    }

    return iframe;
}


function dv_findWindowDepth(currWin) {
    var i = 0;
    while (i < 10 && currWin != window.top) {
        i++;
        currWin = currWin.parent;
    }
    return i;
}

function dv_GetRnd() {
    return ((new Date()).getTime() + "" + Math.floor(Math.random() * 1000000)).substr(0, 16);
}

function dv_findAddUrl(tpWin) {
    try {
        if (tpWin.depth <= 1)
            return { url: '', depth: '' };
        var len;
        var q = new Array();
        q.push({ win: window.top, depth: 0 });
        var curr;
        var queueSize = 1;
        var loopCounter = 0;
        while (queueSize > 0 && loopCounter < 100) {
            try {
                loopCounter++;
                curr = q.shift();
                queueSize--;
                var loc = curr.win.location.toString();
                if (loc.length > 0 && curr.win != tpWin) {
                    if (curr.win.document.referrer.length == 0 || curr.depth == 0) {
                        return { url: curr.win.location, depth: curr.depth };
                    }
                    else {
                        return { url: curr.win.document.referrer, depth: curr.depth - 1 };
                    }
                }
            }
            catch (e) {
            }

            len = curr.win.frames.length;
            for (var idx = 0; idx < len; idx++) {
                q.push({ win: curr.win.frames[idx], depth: curr.depth + 1 });
                queueSize++;
            }
        }
        return { url: '', depth: '' };
    }
    catch (e) {
        return { url: '', depth: '' };
    }
}



try {
    window.parentIsPermitted = false;
    window.DVCurWin = window;
    var dv_referrerOffset = 0;
    var dv_minus = false;
    try {
        for (dv_i = 0; dv_i <= 10; dv_i++) {
            if ((window.DVCurWin.parent != null) && (window.DVCurWin.parent != window.DVCurWin)) {
                var dv_loc = window.DVCurWin.parent.location.toString();
                var dv_x = dv_loc.length;
                if (dv_x > 0) {
                    window.DVCurWin = window.DVCurWin.parent;
                    dv_referrerOffset++;
                    window.parentIsPermitted = true;
                }
                else {
                    window.parentIsPermitted = false;
                    break;
                }
            }
            else {
                if (dv_i == 0) { window.parentIsPermitted = true; }
                break;
            }
        }
    }
    catch (e) {
        window.parentIsPermitted = false;
    }

    if (window.DVCurWin.document.referrer.length == 0) {
        window.DVURL = window.DVCurWin.location;
    }
    else {
        if (window.parentIsPermitted) {
            window.DVURL = window.DVCurWin.location;
        }
        else {
            window.DVURL = window.DVCurWin.document.referrer;
            dv_minus = true;
        }
    }

    var dv_qPageID = null;
    var dv_cUrl = null;
    if (window.external != null) {
        dv_qPageID = window.external.QueuePageID != undefined ? window.external.QueuePageID : null;
        dv_cUrl = window.external.CrawlerUrl != undefined ? window.external.CrawlerUrl : null;
    }

    if (!_dvScripts) var _dvScripts = new Array();
    var dv_scripts = document.getElementsByTagName('script');
    for (dv_i in dv_scripts) {
        var dv_src = dv_scripts[dv_i].src;
        if (dv_src && dv_src.match(/dvtp_src?\.js/) && !dv_Contains(_dvScripts,dv_scripts[dv_i])) {
            _dvScripts[dv_scripts.length] = dv_scripts[dv_i];

            if (dv_src.match("^http:") == "http:" && window.location.toString().match("^https") == "https")
                break;

            var dv_region = dv_GetParam(dv_src, 'region') || "";
            var dv_protocol = "http:";
            var dv_ssl = '0';
            if (dv_src.match("^https") == "https" && window.location.toString().match("^https") == "https") {
                dv_protocol = "https:";
                dv_ssl = '1';
            }

            try {
                window.DVCurWin.depth = dv_findWindowDepth(window.DVCurWin);
                var dv_additionalUrl = dv_findAddUrl(window.DVCurWin);
                var dv_additionalUrlParam = '&aUrl=' + encodeURIComponent(dv_additionalUrl.url) + '&aUrlD=' + dv_additionalUrl.depth;
                var dv_referrerDepth = window.DVCurWin.depth + dv_referrerOffset;
                if (dv_minus) {
                    window.DVCurWin.depth--;
                }
            }
            catch (e) {
                window.DVCurWin.depth = '';
                var dv_additionalUrlParam = '';
                var dv_referrerDepth = '';
            }

            var dv_src = dv_protocol + '//tps' + dv_region + '.doubleverify.com/visit.js?ctx=' + (dv_GetParam(dv_src, 'ctx') || "") + '&cmp=' + (dv_GetParam(dv_src, 'cmp') || "") + '&ipos=' + (dv_GetParam(dv_src, 'ipos') || "") + '&sid=' + (dv_GetParam(dv_src, 'sid') || "") + '&plc=' + (dv_GetParam(dv_src, 'plc') || "") + '&adid=' + (dv_GetParam(dv_src, 'adid') || "") + '&crt=' + (dv_GetParam(dv_src, 'crt') || "") + '&dvtagver=' + (dv_GetParam(dv_src, 'dvtagver') || "") + '&srcurl=' + encodeURIComponent(DVURL) + '&srcurlD=' + window.DVCurWin.depth + '&curl=' + (dv_cUrl == null ? '' : encodeURIComponent(dv_cUrl)) + '&qpgid=' + (dv_qPageID == null ? '' : dv_qPageID) + '&btreg=' + (dv_GetParam(dv_src, 'btreg') || "") + '&btadsrv=' + (dv_GetParam(dv_src, 'btadsrv') || "") + '&adsrv=' + (dv_GetParam(dv_src, 'adsrv') || "") + '&advid=' + (dv_GetParam(dv_src, 'advid') || "") + '&num=' + (dv_GetParam(dv_src, 'num') || "") + '&pid=' + (dv_GetParam(dv_src, 'pid') || "") + '&crtname=' + (dv_GetParam(dv_src, 'crtname') || "") + '&unit=' + (dv_GetParam(dv_src, 'unit') || "") + '&chnl=' + (dv_GetParam(dv_src, 'chnl') || "") + '&ssl=' + dv_ssl + '&uid=' + (dv_GetParam(dv_src, 'uid') || "") + '&scusrid=' + (dv_GetParam(dv_src, 'scusrid') || "") + '&refD=' + dv_referrerDepth;
            var dv_uidParam = dv_GetParam(dv_src, "uid");
            if (dv_uidParam == null) {//param doesn't exist
                var dv_uid = dv_GetRnd();
                dv_src += "&uid=" + dv_uid;
            }
            else if (dv_uidParam == "") {//param exists w/o value
                var dv_uid = dv_GetRnd();
                dv_src = dv_src.replace("&uid=", "&uid=" + dv_uid);
            }
            
            var dv_iframe = dv_createIframe();
            document.body.insertBefore(dv_iframe, document.body.firstChild);
            var dv_iframeDocument = (dv_iframe.contentDocument || dv_iframe.contentWindow.document || window.frames[dv_iframe.name].document);
            
            var dv_charLimit = 4000;
            if (/MSIE (\d+\.\d+);/.test(navigator.userAgent) && (new Number(RegExp.$1) <= 7)) {
                dv_charLimit = 2000;
            }

            var dv_userAgent = navigator.userAgent.toLowerCase();
            if (dv_userAgent.indexOf('webkit') > -1 || dv_userAgent.indexOf('chrome') > -1) {
                var dv_referrerParam = '&referrer=' + encodeURIComponent(dv_iframeDocument.referrer);
                if (dv_src.length+dv_referrerParam.length <= dv_charLimit) {
                    dv_src += dv_referrerParam;
                }
            }
            
            if (dv_additionalUrlParam.length + dv_src.length <= dv_charLimit) {
                dv_src += dv_additionalUrlParam;
            }
            
            dv_iframeDocument.open();
            dv_iframeDocument.write('<html><head><\/head><body><scr' + 'ipt type="text/javascript" src="' + dv_src + '"><\/scr' + 'ipt><scr' + 'ipt type="text/javascript">var script = document.getElementsByTagName("script")[0]; if (script.readyState) { script.onreadystatechange = function() { if (script.readyState == "complete") document.close(); } } else document.close();<\/scr' + 'ipt><\/body><\/html>');
            break;

        }
    }
}
catch (ex) { }
