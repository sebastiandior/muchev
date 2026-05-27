<?xml version="1.0" encoding="UTF-8"?>
<vstgui-ui-description version="1">

  <!--
    mu-law — Hikari Audio
    Steel panel UI
    580 x 380 px
  -->

  <fonts>
    <font name="label-font"  font-name="Arial" size="9"  bold="false" italic="false"/>
    <font name="value-font"  font-name="Arial" size="11" bold="false" italic="false"/>
    <font name="title-font"  font-name="Arial" size="20" bold="false" italic="false"/>
    <font name="brand-font"  font-name="Arial" size="10" bold="false" italic="false"/>
    <font name="chain-font"  font-name="Arial" size="9"  bold="false" italic="false"/>
    <font name="chain-val-font" font-name="Arial" size="11" bold="true"  italic="false"/>
  </fonts>

  <colors>
    <!-- Panel steel tones -->
    <color name="panel-bg"        red="184" green="190" blue="200" alpha="255"/>
    <color name="panel-inset"     red="196" green="202" blue="212" alpha="255"/>
    <color name="panel-border"    red="154" green="160" blue="170" alpha="255"/>
    <color name="inset-border"    red="168" green="174" blue="184" alpha="255"/>
    <color name="section-bg"      red="173" green="179" blue="189" alpha="255"/>
    <color name="section-border"  red="154" green="160" blue="170" alpha="255"/>

    <!-- Knob colors -->
    <color name="knob-body"       red="176" green="182" blue="192" alpha="255"/>
    <color name="knob-face"       red="192" green="198" blue="208" alpha="255"/>
    <color name="knob-border"     red="138" green="144" blue="152" alpha="255"/>
    <color name="knob-marker"     red="58"  green="64"  blue="80"  alpha="255"/>

    <!-- Arc colors per knob -->
    <color name="arc-drive"       red="122" green="85"  blue="48"  alpha="255"/>
    <color name="arc-mu"          red="42"  green="74"  blue="110" alpha="255"/>
    <color name="arc-output"      red="74"  green="90"  blue="74"  alpha="255"/>
    <color name="arc-speed"       red="90"  green="90"  blue="112" alpha="255"/>
    <color name="arc-track"       red="138" green="144" blue="152" alpha="255"/>

    <!-- Text colors -->
    <color name="label-color"     red="74"  green="80"  blue="96"  alpha="255"/>
    <color name="value-color"     red="58"  green="64"  blue="80"  alpha="255"/>
    <color name="title-color"     red="42"  green="48"  blue="64"  alpha="255"/>
    <color name="brand-color"     red="90"  green="96"  blue="112" alpha="255"/>
    <color name="chain-label"     red="90"  green="96"  blue="112" alpha="255"/>
    <color name="chain-value"     red="42"  green="48"  blue="64"  alpha="255"/>
    <color name="footer-muted"    red="90"  green="96"  blue="112" alpha="255"/>

    <!-- Meter colors -->
    <color name="meter-fast"      red="122" green="85"  blue="48"  alpha="255"/>
    <color name="meter-slow"      red="42"  green="74"  blue="110" alpha="255"/>
    <color name="meter-track"     red="154" green="160" blue="170" alpha="255"/>

    <!-- Character strip -->
    <color name="char-thumb"      red="208" green="214" blue="224" alpha="255"/>
    <color name="char-thumb-brd"  red="122" green="128" blue="138" alpha="255"/>

    <!-- Bypass button states -->
    <color name="bypass-bg"       red="184" green="190" blue="200" alpha="255"/>
    <color name="bypass-bg-on"    red="200" green="212" blue="192" alpha="255"/>
    <color name="bypass-border"   red="138" green="144" blue="152" alpha="255"/>
    <color name="bypass-border-on" red="106" green="138" blue="106" alpha="255"/>
    <color name="bypass-text"     red="58"  green="64"  blue="80"  alpha="255"/>
    <color name="bypass-text-on"  red="42"  green="74"  blue="42"  alpha="255"/>

    <!-- Value display bg -->
    <color name="value-bg"        red="176" green="182" blue="192" alpha="255"/>
    <color name="value-border"    red="154" green="160" blue="170" alpha="255"/>

    <!-- Screw color -->
    <color name="screw-color"     red="154" green="160" blue="170" alpha="255"/>
    <color name="screw-slot"      red="106" green="112" blue="122" alpha="255"/>

    <!-- Separator -->
    <color name="separator"       red="160" green="166" blue="176" alpha="255"/>

    <color name="transparent"     red="0"   green="0"   blue="0"   alpha="0"/>
    <color name="white"           red="255" green="255" blue="255" alpha="255"/>
  </colors>

  <control-tags>
    <control-tag name="InputDrive"  tag="0"/>
    <control-tag name="OutputGain"  tag="1"/>
    <control-tag name="Mu"          tag="2"/>
    <control-tag name="Character"   tag="3"/>
    <control-tag name="Speed"       tag="4"/>
    <control-tag name="Bypass"      tag="5"/>
  </control-tags>

  <templates>
    <template name="editor" size="580,400" background-color="panel-bg" minSize="580,400" maxSize="580,400">

      <!-- Outer panel border -->
      <view class="CViewContainer" origin="0,0" size="580,400"
            background-color="panel-bg">

        <!-- Corner screws — top row -->
        <view class="CView" origin="14,12"  size="10,10" background-color="screw-color" corner-radius="5"/>
        <view class="CView" origin="556,12" size="10,10" background-color="screw-color" corner-radius="5"/>

        <!-- Corner screws — bottom row -->
        <view class="CView" origin="14,378" size="10,10" background-color="screw-color" corner-radius="5"/>
        <view class="CView" origin="556,378" size="10,10" background-color="screw-color" corner-radius="5"/>

        <!-- Inner inset panel -->
        <view class="CViewContainer" origin="30,30" size="520,340"
              background-color="panel-inset" corner-radius="7">

          <!-- Header separator -->
          <view class="CView" origin="0,52" size="520,1" background-color="separator"/>

          <!-- Brand label -->
          <view class="CTextLabel" origin="18,12" size="200,14"
                font="brand-font" font-color="brand-color"
                text="HIKARI AUDIO" transparent="true"
                text-alignment="left" style-no-frame="true"/>

          <!-- Plugin name -->
          <view class="CTextLabel" origin="16,24" size="200,24"
                font="title-font" font-color="title-color"
                text="μ-Law" transparent="true"
                text-alignment="left" style-no-frame="true"/>

          <!-- Version -->
          <view class="CTextLabel" origin="460,30" size="46,14"
                font="label-font" font-color="brand-color"
                text="v1.1.0" transparent="true"
                text-alignment="right" style-no-frame="true"/>

          <!-- ═══ KNOBS ROW ═══ -->

          <!-- DRIVE knob -->
          <view class="CTextLabel" origin="34,64" size="74,12"
                font="label-font" font-color="label-color"
                text="DRIVE" transparent="true"
                text-alignment="center" style-no-frame="true"/>
          <view class="CKnob" origin="42,78" size="58,58"
                control-tag="InputDrive"
                angle-start="4.7124" angle-range="4.7124"
                inset-value="6"
                handle-color="knob-marker"
                corona-color="arc-drive"
                background-color="knob-body"
                color-shadow-handle="transparent"
                draw-back-color="knob-face"
                draw-back="true"
                handle-line-width="2"
                corona-line-width="2.5"
                corona-from-center="false"
                skip-corona-from-selection="false"
                value="0.25"/>
          <view class="CParamDisplay" origin="36,140" size="70,18"
                control-tag="InputDrive"
                font="value-font" font-color="value-color"
                back-color="value-bg"
                frame-color="value-border"
                precision="2"
                value-to-string="false"
                style-no-frame="false"
                corner-radius="3"/>

          <!-- MU knob -->
          <view class="CTextLabel" origin="148,64" size="74,12"
                font="label-font" font-color="label-color"
                text="MU" transparent="true"
                text-alignment="center" style-no-frame="true"/>
          <view class="CKnob" origin="156,78" size="58,58"
                control-tag="Mu"
                angle-start="4.7124" angle-range="4.7124"
                inset-value="6"
                handle-color="knob-marker"
                corona-color="arc-mu"
                background-color="knob-body"
                color-shadow-handle="transparent"
                draw-back-color="knob-face"
                draw-back="true"
                handle-line-width="2"
                corona-line-width="2.5"
                corona-from-center="false"
                value="0.5"/>
          <view class="CParamDisplay" origin="150,140" size="70,18"
                control-tag="Mu"
                font="value-font" font-color="value-color"
                back-color="value-bg"
                frame-color="value-border"
                precision="2"
                style-no-frame="false"
                corner-radius="3"/>

          <!-- OUTPUT knob -->
          <view class="CTextLabel" origin="262,64" size="74,12"
                font="label-font" font-color="label-color"
                text="OUTPUT" transparent="true"
                text-alignment="center" style-no-frame="true"/>
          <view class="CKnob" origin="270,78" size="58,58"
                control-tag="OutputGain"
                angle-start="4.7124" angle-range="4.7124"
                inset-value="6"
                handle-color="knob-marker"
                corona-color="arc-output"
                background-color="knob-body"
                color-shadow-handle="transparent"
                draw-back-color="knob-face"
                draw-back="true"
                handle-line-width="2"
                corona-line-width="2.5"
                corona-from-center="false"
                value="0.5"/>
          <view class="CParamDisplay" origin="264,140" size="70,18"
                control-tag="OutputGain"
                font="value-font" font-color="value-color"
                back-color="value-bg"
                frame-color="value-border"
                precision="2"
                style-no-frame="false"
                corner-radius="3"/>

          <!-- SPEED knob -->
          <view class="CTextLabel" origin="376,64" size="74,12"
                font="label-font" font-color="label-color"
                text="SPEED" transparent="true"
                text-alignment="center" style-no-frame="true"/>
          <view class="CKnob" origin="384,78" size="58,58"
                control-tag="Speed"
                angle-start="4.7124" angle-range="4.7124"
                inset-value="6"
                handle-color="knob-marker"
                corona-color="arc-speed"
                background-color="knob-body"
                color-shadow-handle="transparent"
                draw-back-color="knob-face"
                draw-back="true"
                handle-line-width="2"
                corona-line-width="2.5"
                corona-from-center="false"
                value="0.5"/>
          <view class="CParamDisplay" origin="378,140" size="70,18"
                control-tag="Speed"
                font="value-font" font-color="value-color"
                back-color="value-bg"
                frame-color="value-border"
                precision="2"
                style-no-frame="false"
                corner-radius="3"/>

          <!-- ═══ SIGNAL CHAIN BAR ═══ -->
          <view class="CViewContainer" origin="14,170" size="492,38"
                background-color="section-bg" corner-radius="5">

            <!-- In stage -->
            <view class="CViewContainer" origin="6,5" size="100,28"
                  background-color="panel-inset" corner-radius="4">
              <view class="CTextLabel" origin="0,3" size="100,11"
                    font="chain-font" font-color="chain-label"
                    text="IN" transparent="true"
                    text-alignment="center" style-no-frame="true"/>
              <view class="CParamDisplay" origin="10,15" size="80,11"
                    control-tag="InputDrive"
                    font="chain-val-font" font-color="chain-value"
                    back-color="transparent"
                    frame-color="transparent"
                    precision="2"
                    style-no-frame="true"
                    text-alignment="center"/>
            </view>

            <view class="CTextLabel" origin="106,13" size="12,12"
                  font="chain-val-font" font-color="chain-label"
                  text="›" transparent="true"
                  text-alignment="center" style-no-frame="true"/>

            <!-- μ-Law stage -->
            <view class="CViewContainer" origin="118,5" size="100,28"
                  background-color="panel-inset" corner-radius="4">
              <view class="CTextLabel" origin="0,3" size="100,11"
                    font="chain-font" font-color="chain-label"
                    text="μ-LAW" transparent="true"
                    text-alignment="center" style-no-frame="true"/>
              <view class="CParamDisplay" origin="10,15" size="80,11"
                    control-tag="Mu"
                    font="chain-val-font" font-color="chain-value"
                    back-color="transparent"
                    frame-color="transparent"
                    precision="2"
                    style-no-frame="true"
                    text-alignment="center"/>
            </view>

            <view class="CTextLabel" origin="218,13" size="12,12"
                  font="chain-val-font" font-color="chain-label"
                  text="›" transparent="true"
                  text-alignment="center" style-no-frame="true"/>

            <!-- Chebyshev stage -->
            <view class="CViewContainer" origin="230,5" size="100,28"
                  background-color="panel-inset" corner-radius="4">
              <view class="CTextLabel" origin="0,3" size="100,11"
                    font="chain-font" font-color="chain-label"
                    text="CHEBY" transparent="true"
                    text-alignment="center" style-no-frame="true"/>
              <view class="CParamDisplay" origin="10,15" size="80,11"
                    control-tag="Character"
                    font="chain-val-font" font-color="chain-value"
                    back-color="transparent"
                    frame-color="transparent"
                    precision="2"
                    style-no-frame="true"
                    text-alignment="center"/>
            </view>

            <view class="CTextLabel" origin="330,13" size="12,12"
                  font="chain-val-font" font-color="chain-label"
                  text="›" transparent="true"
                  text-alignment="center" style-no-frame="true"/>

            <!-- Out stage -->
            <view class="CViewContainer" origin="342,5" size="144,28"
                  background-color="panel-inset" corner-radius="4">
              <view class="CTextLabel" origin="0,3" size="144,11"
                    font="chain-font" font-color="chain-label"
                    text="OUT" transparent="true"
                    text-alignment="center" style-no-frame="true"/>
              <view class="CParamDisplay" origin="10,15" size="124,11"
                    control-tag="OutputGain"
                    font="chain-val-font" font-color="chain-value"
                    back-color="transparent"
                    frame-color="transparent"
                    precision="2"
                    style-no-frame="true"
                    text-alignment="center"/>
            </view>
          </view>

          <!-- ═══ ENVELOPE METERS ═══ -->

          <!-- Fast env meter block -->
          <view class="CViewContainer" origin="14,218" size="240,48"
                background-color="section-bg" corner-radius="5">
            <view class="CTextLabel" origin="10,7" size="220,11"
                  font="label-font" font-color="label-color"
                  text="FAST ENV — TRANSIENT" transparent="true"
                  text-alignment="left" style-no-frame="true"/>
            <view class="CVuMeter" origin="10,22" size="220,6"
                  control-tag="InputDrive"
                  back-color="meter-track"
                  fore-color="meter-fast"
                  orientation="horizontal"
                  num-led="1"
                  decrease-step-value="0.001"/>
            <view class="CTextLabel" origin="10,32" size="100,12"
                  font="label-font" font-color="chain-label"
                  text="atk 5ms" transparent="true"
                  text-alignment="left" style-no-frame="true"/>
            <view class="CTextLabel" origin="130,32" size="100,12"
                  font="label-font" font-color="chain-label"
                  text="rel 50ms" transparent="true"
                  text-alignment="right" style-no-frame="true"/>
          </view>

          <!-- Slow env meter block -->
          <view class="CViewContainer" origin="266,218" size="240,48"
                background-color="section-bg" corner-radius="5">
            <view class="CTextLabel" origin="10,7" size="220,11"
                  font="label-font" font-color="label-color"
                  text="SLOW ENV — BIAS DRIFT" transparent="true"
                  text-alignment="left" style-no-frame="true"/>
            <view class="CVuMeter" origin="10,22" size="220,6"
                  control-tag="Mu"
                  back-color="meter-track"
                  fore-color="meter-slow"
                  orientation="horizontal"
                  num-led="1"
                  decrease-step-value="0.0001"/>
            <view class="CTextLabel" origin="10,32" size="100,12"
                  font="label-font" font-color="chain-label"
                  text="atk 80ms" transparent="true"
                  text-alignment="left" style-no-frame="true"/>
            <view class="CTextLabel" origin="130,32" size="100,12"
                  font="label-font" font-color="chain-label"
                  text="rel 400ms" transparent="true"
                  text-alignment="right" style-no-frame="true"/>
          </view>

          <!-- ═══ CHARACTER STRIP ═══ -->
          <view class="CViewContainer" origin="14,276" size="492,46"
                background-color="section-bg" corner-radius="5">

            <view class="CTextLabel" origin="10,7" size="220,11"
                  font="label-font" font-color="label-color"
                  text="TUBE — 2ND HARMONIC" transparent="true"
                  text-alignment="left" style-no-frame="true"/>
            <view class="CTextLabel" origin="262,7" size="220,11"
                  font="label-font" font-color="label-color"
                  text="TRANSFORMER — 3RD HARMONIC" transparent="true"
                  text-alignment="right" style-no-frame="true"/>

            <!-- Character slider -->
            <view class="CSlider" origin="10,20" size="472,10"
                  control-tag="Character"
                  orientation="horizontal"
                  background-color="meter-track"
                  handle-color="char-thumb"
                  frame-color="section-border"
                  handle-offset="5,0"
                  value="0.0"
                  wheel-inc-value="0.02"/>

            <view class="CTextLabel" origin="10,33" size="60,10"
                  font="label-font" font-color="chain-label"
                  text="Tube" transparent="true"
                  text-alignment="left" style-no-frame="true"/>
            <view class="CTextLabel" origin="206,33" size="80,10"
                  font="label-font" font-color="chain-label"
                  text="Blend" transparent="true"
                  text-alignment="center" style-no-frame="true"/>
            <view class="CTextLabel" origin="422,33" size="60,10"
                  font="label-font" font-color="chain-label"
                  text="Xfmr" transparent="true"
                  text-alignment="right" style-no-frame="true"/>
          </view>

          <!-- ═══ FOOTER ═══ -->
          <view class="CView" origin="14,330" size="492,1" background-color="separator"/>

          <!-- Bypass button -->
          <view class="CTextButton" origin="14,336" size="72,18"
                control-tag="Bypass"
                title="Active"
                title-active="Bypassed"
                font="label-font"
                text-color="bypass-text-on"
                text-color-active="bypass-text"
                gradient-top-color="bypass-bg-on"
                gradient-top-color-active="bypass-bg"
                gradient-bottom-color="bypass-bg-on"
                gradient-bottom-color-active="bypass-bg"
                frame-color="bypass-border-on"
                frame-color-active="bypass-border"
                round-radius="4"
                frame-width="1"
                style-kickbutton="true"
                value="0"/>

          <!-- Hikari Audio footer label -->
          <view class="CTextLabel" origin="380,336" size="126,18"
                font="brand-font" font-color="footer-muted"
                text="Hikari Audio" transparent="true"
                text-alignment="right" style-no-frame="true"/>

        </view>
      </view>
    </template>
  </templates>

</vstgui-ui-description>
