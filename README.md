# KHR-3HV

## 方針

* Visual Studioプロジェクト
* 言語はC++
* CMakeでビルド
* 開発の主はMIYATANIkoki．atom-2003は基本的に大人しくしとく

## ロードマップ

1. Serial通信を確立
外部コンピュータで計算した値を、Serial通信用のデータに置き換えるプログラムを書く
Serial通信用のコードを記述する際に楽になるような関数が用意されているライブラリであるRcb4.dllと、Extensions.dllを用いる
2. サーボを一個動かす
3. 複数サーボを動かす
4. 全身運動を生成する

## ディレクトリ構成

bin 実行ファイルの生成先
cmake CMakeListが参照する定型文を保存する場所
program 実行ファイルの元となるソースコードやライブラリの保管場所

CMakeList.txt
license.txt
README.md

## ビルド方法

1. ルートディレクトリにbuildフォルダを作成
2. CMakeでConfigure, Generate
3. Visual Studioでソリューションのビルド(Debug/Release)
4. ALL_BUILDをビルド
5. スタートアッププロジェクトにmainを選び、ローカルwindowsデバッガを使用すると、実行できる