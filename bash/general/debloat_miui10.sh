#!/bin/bash

adb shell pm uninstall -k --user 0 com.xiaomi.gamecenter
adb shell pm uninstall -k --user 0 com.xiaomi.vipaccount
adb shell pm uninstall -k --user 0 com.xiaomi.scanner
adb shell pm uninstall -k --user 0 com.xiaomi.payment
adb shell pm uninstall -k --user 0 com.xiaomi.smarthome
adb shell pm uninstall -k --user 0 com.xiaomi.o2o
adb shell pm uninstall -k --user 0 com.xiaomi.jr
adb shell pm uninstall -k --user 0 com.xiaomi.jr.security
adb shell pm uninstall -k --user 0 com.xiaomi.youpin
adb shell pm uninstall -k --user 0 com.xiaomi.shop
adb shell pm uninstall -k --user 0 com.xiaomi.mibrain.speech
adb shell pm uninstall -k --user 0 com.xiaomi.mimobile.noti

adb shell pm uninstall -k --user 0 com.miui.fm
adb shell pm uninstall -k --user 0 com.miui.compass
adb shell pm uninstall -k --user 0 com.miui.miuibbs
adb shell pm uninstall -k --user 0 com.miui.video
adb shell pm uninstall -k --user 0 com.miui.screenrecorder
adb shell pm uninstall -k --user 0 com.miui.hybrid
adb shell pm uninstall -k --user 0 com.miui.weather2
adb shell pm uninstall -k --user 0 com.miui.virtualsim
adb shell pm uninstall -k --user 0 com.miui.bugreport
adb shell pm uninstall -k --user 0 com.miui.voiceassist
adb shell pm uninstall -k --user 0 com.miui.yellowpage
adb shell pm uninstall -k --user 0 com.miui.personalassistant

adb shell pm uninstall -k --user 0 com.mi.liveassistant
adb shell pm uninstall -k --user 0 com.mipay.wallet

adb shell pm uninstall -k --user 0 com.android.email
adb shell pm uninstall -k --user 0 com.android.midrive
adb shell pm uninstall -k --user 0 com.android.soundrecorder

adb shell pm uninstall -k --user 0 com.wali.live
adb shell pm uninstall -k --user 0 com.xiangkan.android
adb shell pm uninstall -k --user 0 com.codeaurora.fmradio
adb shell pm uninstall -k --user 0 com.duokan.phone.remotecontroller
adb shell pm uninstall -k --user 0 com.sohu.inputmethod.sogou.xiaomi
adb shell pm uninstall -k --user 0 com.google.android.marvin.talkback

adb reboot

# NEVER DEBLOAT !!!
# com.xiaomi.market (App Store)
# com.xiaomi.account (Mi Account)
# com.android.quicksearchbox (Search)
# com.android.thememanager (Theme Manager)
