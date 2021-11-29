object FormFindCustomers: TFormFindCustomers
  Left = 0
  Top = 0
  Caption = 'FormFindCustomers'
  ClientHeight = 362
  ClientWidth = 764
  Color = clBtnFace
  Font.Charset = DEFAULT_CHARSET
  Font.Color = clWindowText
  Font.Height = -11
  Font.Name = 'Tahoma'
  Font.Style = []
  OldCreateOrder = False
  OnCanResize = FormCanResize
  OnCreate = FormCreate
  PixelsPerInch = 96
  TextHeight = 13
  object PanelBottom: TPanel
    Left = 0
    Top = 314
    Width = 764
    Height = 48
    Align = alBottom
    TabOrder = 0
    object ButtonClose: TButton
      Left = 133
      Top = 11
      Width = 75
      Height = 25
      Caption = '&Close'
      TabOrder = 0
      OnClick = ButtonCloseClick
    end
  end
  object PanelRight: TPanel
    Left = 340
    Top = 0
    Width = 424
    Height = 314
    Align = alClient
    TabOrder = 1
    object Grid: TStringGrid
      AlignWithMargins = True
      Left = 5
      Top = 5
      Width = 414
      Height = 263
      Margins.Left = 4
      Margins.Top = 4
      Margins.Right = 4
      Margins.Bottom = 4
      Align = alClient
      BevelKind = bkFlat
      DoubleBuffered = True
      Options = [goFixedVertLine, goFixedHorzLine, goVertLine, goHorzLine]
      ParentDoubleBuffered = False
      TabOrder = 0
      OnDblClick = GridDblClick
    end
    object PanelInfo: TPanel
      Left = 1
      Top = 272
      Width = 422
      Height = 41
      Align = alBottom
      TabOrder = 1
      object LabelInfo: TLabel
        Left = 1
        Top = 1
        Width = 420
        Height = 39
        Align = alClient
        AutoSize = False
        Font.Charset = DEFAULT_CHARSET
        Font.Color = clBlack
        Font.Height = -13
        Font.Name = 'Tahoma'
        Font.Style = [fsBold]
        ParentFont = False
        ExplicitLeft = 8
        ExplicitTop = 6
        ExplicitWidth = 376
        ExplicitHeight = 30
      end
    end
  end
  object PanelLeft: TPanel
    Left = 0
    Top = 0
    Width = 340
    Height = 314
    Align = alLeft
    TabOrder = 2
    object Label6: TLabel
      Left = 47
      Top = 140
      Width = 80
      Height = 13
      Alignment = taRightJustify
      AutoSize = False
      Caption = 'Budget (eu) :'
    end
    object Label7: TLabel
      Left = 47
      Top = 103
      Width = 80
      Height = 13
      Alignment = taRightJustify
      AutoSize = False
      Caption = 'City :'
    end
    object Label2: TLabel
      Left = 64
      Top = 70
      Width = 63
      Height = 13
      Alignment = taRightJustify
      AutoSize = False
      Caption = 'Last Name :'
    end
    object Label1: TLabel
      Left = 64
      Top = 37
      Width = 63
      Height = 13
      Alignment = taRightJustify
      AutoSize = False
      Caption = 'First Name :'
    end
    object SpeedButtonFind: TSpeedButton
      Left = 251
      Top = 251
      Width = 42
      Height = 42
      Hint = 'Executes Query'
      Glyph.Data = {
        360C0000424D360C000000000000360000002800000020000000200000000100
        180000000000000C0000EC000000EC0000000000000000000000FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFC8C8C8999999DDDDDDFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFF8787890B0C170D0D4807080EDDDDDDFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFF8686880D0F1D2E3AD32529D60C0D49929292FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFF8686880D0F1D2E3AD33441F21D1DB2070716C7C7C7FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFDFDFDDBDBDBC0C0C0CCCCCCEBEBEBFFFFFFFFFFFFFFFFFFFF
        FFFFA1A1A20D0F1D2E3AD33441F21E21B607071A828387FFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFCECECE5C5C5C0C0C0C1616162929291E1E1E0B0B0B1C1C1C7E7E7EEEEEEEF9
        F9F9383838141529303CE01E21B607071A828387FFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF8F8F86767
        670F0F0F5555558A8A8A9797978888888C8C8C9999996D6D6D2D2D2D0F0F0F37
        37362D2B283D3A350E0E25070719838488FFFFFFFFFFFFFFFFFFFFFFFFE6E6E6
        DDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDDD8D8D83838383030
        3092929267676728251C0403021712060E0A030A07033C372C7E7E7E5D5D5D0E
        0E0D45423C2C2B27373737A1A1A1FFFFFFFFFFFFFFFFFFFFFFFF5C6465040809
        071011071011071011071011020405040A0B071011040E100000003737379393
        932F2C26261C07A06F01E9A202F4A902F4A902CD8C036541020D090256535069
        69690F0F0E373737F8F8F8FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF03050500C6E6
        00DCFF00DCFF00DCFF00DCFF0B434C0090A702D4FF057DA4171B1C9595952623
        1D583E05EDA402F4A902F4A902F4A902F4A902F4A902F2A702AE72021E140252
        504C5757570F0F0FF0F0F0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000D1F2
        057F920306070A3E4700D8FA0B434C0090A707C5FD091D236E6E6E504F4D3D2C
        06F1A702F4A902F4A902F4A902F4A902F4A902F4A902F4A902EFA402A56A030E
        0A026969692A2A2A7C7C7CFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000D1F2
        0C2226A6A6A60F151600B2CE0B434C018CA70699C91014159797970B0A05CD8E
        02F4A902F4A902F4A902F4A902F4A902F4A902F4A902F4A902F4A902D890025F
        3C02393429565656202020FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000D1F2
        066F7F0203030A2C3200D5F70B434C0388A7046B8C3D3F3F6F6F6F302409F4A9
        02F4A902F4A902F4A902F4A902F4A902F4A902F4A902F4A902F4A902ECA202A4
        68030A08036E6E6E070707E5E5E5FFFFFFFFFFFFFFFFFFFFFFFF01020200CBEB
        00DCFF00CFF000DBFE00DCFF0B434C0386A605556E525252555555614506F4A9
        02F4A902F4A902F4A902F4A902F4A902F4A902F4A902F4A902F4A902F4A802BE
        79030C0902686868181818CCCCCCFFFFFFFFFFFFFFFFFFFFFFFF475051071417
        081C22081C22081C22081C2203080A031116020A0D545454525252684904F4A9
        02F4A902F4A902F4A902F4A902F4A902F4A902F4A902F4A902F4A902F4A902BE
        7A03130D026666661A1A1AC1C1C1FFFFFFFFFFFFFFFFFFFFFFFFFDFDFD070A0C
        016EB8017ACC017ACC017ACC017ACC017ACC00406B474747646464453209F4A9
        02F4A902F4A902F4A902F4A902F4A902F4A902F4A902F4A902F4A902F0A502B3
        71030504016E6E6E0D0D0DDEDEDEFFFFFFFFFFFFFFFFFFFFFFFFB9B9B9030405
        0A293D0B2E440B2E440B2E440B2E440A3044051E2A2225268C8C8C0A0804E7A0
        02F4A902F4A902F4A902F4A902F4A902F4A902F4A902F4A902F4A902E097027C
        4E022922166262620A0A0AFBFBFBFFFFFFFFFFFFFFFFFFFFFFFF0C1213007B8F
        0093AA0093AA0093AA0093AA072C320060700581A8070E1085858534322C7452
        04F4A902F5EBD4F4C55DF4A903F4A902F4A902F4A902F4A902F3A802C27C0222
        16025959593A3A3A5A5A5AFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000D1F2
        00BAD8055D6B0193AA00DCFF0B434C0090A704CEFE075D783637388A8A8A0F0D
        08A87501F4BA37F5E8CCF5EBD5F4DBA4F5B527F4A902F4A902D68F03482E0130
        2B206A6A6A0C0C0CCDCDCDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000D1F2
        0C3036606262080F1000BEDC0B434C0090A700DBFF07BCF1091A1F6262627878
        78110E08755203E7A104F4BA38F4C55CF4AE14F3A802B4780333210228231978
        7878232323666666FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000D1F2
        0B3940414747070E0F00C5E40B434C0090A700DCFF01D8FF069FCD080F116262
        628A8A8A35332C0B0904453209664703593D052B1D040C0904514F4B7E7E7E28
        2828393939F6F6F6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000D1F2
        00C8E800798C00AAC500DCFF0B434C0090A700DCFF00DCFF01DAFF04A5CF0819
        1D3637388686868D8D8D6464645454545757576F6F6F9393935959591414144B
        4B4BF5F5F5FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF141B1C016170
        007588007588007588007588062328004D590075880075880075880075880169
        7D010E110001012227284546465353534B4B4B343434101010000000717171FF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFD0D0D0040607
        063A5C063F66063F66063F660640660641660641660641660641660641660641
        660641660641660642660742660D3F600A3F63074066074066074066070A0CF5
        F5F5FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF4F4F406090A
        015B990165AA0165AA0165AA0165AA0165AA0165AA0165AA0165AA0165AA0165
        AA0165AA0165AA0165AA0165AA0165AA0165AA0165AA0165AA0165AA020405DC
        DCDCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF313A3C0B2C32
        0B39440B39440B39440B394405111407252D0B39440B39440B39440B39440B39
        440B39440B39440B39440B39440B39440B39440B39440B39440A3744032D3A14
        2125FEFEFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF01010100CEEF
        00DBFE00B3CF00D1F200DCFF0B434C0090A700DCFF00DCFF00DCFF00DCFF00DC
        FF00DCFF00DCFF00DCFF00DCFF00DCFF00DCFF00DCFF00DCFF00DCFF08C2FE03
        0F12DFDFDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000D1F2
        095A670E1415081B1E00D1F20B434C0090A700DCFF00B9D700B0CC00B0CC00B0
        CC00B0CC00B0CC00B0CC00B0CC00C5E400DCFF00B9D600B0CC00D3F508C2FE03
        1115DDDDDDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000D1F2
        0C23279393930E141500B3CF0B434C0090A700D9FB002930001D22001D22001D
        22001D22001D22001D22001D2200556300D5F700272D001D220094AB08C2FE03
        1115DDDDDDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF00000000D1F2
        0194AB0C2428095A6700DBFE0B434C0090A700DCFF00DCFF00DCFF00DCFF00DC
        FF00DCFF00DCFF00DCFF00DCFF00DCFF00DCFF00DCFF00DCFF00DCFF08C2FE03
        1115DDDDDDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF04070800B3D0
        00CDEE00CDEE00CDEE00CDEE0B3F4700879C00CDEE00CDEE00CDEE00CDEE00CD
        EE00CDEE00CDEE00CDEE00CDEE00CDEE00CDEE00CDEE00CDEE00CDEE07ADE302
        090BE6E6E6FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF7B8081050808
        0000000000000000000000000000000000000000000000000000000000000000
        0000000000000000000000000000000000000000000000000000000002050554
        6265FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
      ParentShowHint = False
      ShowHint = True
      OnClick = SpeedButtonFindClick
    end
    object Label3: TLabel
      Left = 32
      Top = 275
      Width = 58
      Height = 13
      Alignment = taRightJustify
      AutoSize = False
      Caption = 'Sort by :'
    end
    object Label4: TLabel
      Left = 52
      Top = 174
      Width = 75
      Height = 13
      Alignment = taRightJustify
      AutoSize = False
      Caption = 'Ownership  :'
    end
    object SpeedButtonClear: TSpeedButton
      Left = 18
      Top = 32
      Width = 42
      Height = 42
      Hint = 'Clear Fields'
      Glyph.Data = {
        360C0000424D360C000000000000360000002800000020000000200000000100
        180000000000000C0000120B0000120B00000000000000000000FFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFBDF2FFBFECFBFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDBFAFF65DCFF36EAFF55C9F2FF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFEFFCFF8AF2FF2FCEFF30E0FF2AD1FF25C8FFD4
        F1FBFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFBFEFFA6EEFF44E7FF2DD4FF29D0FF2BDCFF1FC0F825DAFF72
        CEF1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFC7F7FF54DFFF2ED6FF2FDEFF23C5FB2BDFFF1FC0F920CFFF21CBFF23
        BCF7F3FBFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFE1FA
        FF6FE4FF34E4FF28C9FF2EE4FF20C1F925D8FF20C7FF1BC2FF25D4FF21BBF619
        CBFFA1DDF5FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF3FDFF93F2FF33CF
        FF34E7FF25C5FA2BDEFF21C5FF1FCCFF22D0FF1ABBF723D4FF26BEFA13C0FF34
        CFFF3EBBEEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDFFFFAFF1FF47E4FF2ED9FF2FE2
        FF24C7FF25D2FF24CFFF1BC0FB23D6FF20BAF61BCEFF2CC6FF16B9F931D1FF38
        BFF70DBBFFD3EEFAFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFCFF8FF58DAFF35E8FF26C6FB2DE2FF25D2
        FF1FC6FF25D6FF1AB9F521D5FF25BEF914C2FF32CEFF24B8F323CDFF3EC5FB12
        B6FA42D2FF80B9C8F3EEE5FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFE6FAFF7CF1FF2CC9FE33E7FF24C5FB2ADCFF21C7FF1FCF
        FF21D7FF1FBBF61CCEFF29C6FF15BBFB33D1FF2FBBF316C5FF44CAFF22B7F64A
        C2EE999A7CCE934DCE9351F8EFE5FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFF6FEFF97EAFF3FEAFF2ACAFF2DDFFF24C9FF24D0FF22CFFF1BC1FE24D5
        FF15C2FF15C4FF2FCEFF1DB8F62CD0FF3AC0F70EBBFF48CFFF39B7EA75A19CC9
        914FD19753CF9552E0A868E0B788FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFFFF
        B9F6FF47DAFF31DFFF2AD0FF27D4FF26D1FF1EC5FF24D5FF19BAF724D6FF21BB
        F61ACBFF12C7FF28B9F320CBFF41C6FB10B7FD49D0FF67A5B2B89359D19753CE
        944FD8A05EE8B275EDB97DE7B073F4E5D3FFFFFFFFFFFFFFFFFFE5FDFF63E4FF
        30DCFF2BD2FF2BD8FF23C8FF27D7FF1CBEF823D8FF1CB9F51FD1FF28C0F914C3
        FF39CBFF0BB7FE0CC1FF48CBFF19B5F75ABEDEA89366D09652CF9450D59B58E6
        B073EBB87DF0BD83F5C289F8C78FE7BB88FFFFFFFFFFFFFFFFFFF8FEFF64F2FF
        25C8FF2BDDFF1EC0F925D9FF1ABAF522D6FF22BCF719CDFF31C5FF12BBFF3AD0
        FF21B7F32CCEFF07B7FF38B2E18EA08ACE934FD09552D19754E5B278F5C997F3
        C690F3C188F7C68EFBCC95FFD09CEEBA7DFCF8F2FFFFFFFFFFFFFFFFFFECFDFF
        45E6FF1CBDF623D8FF1CBBF61ED1FF26BFFA15C6FF37CAFF16B8F936D0FF2DBA
        F325CAFF51C4F2679D9CC59151D19753CF9550DFAB6EFAD7ACFED9AFF6C68FF6
        C58CFACA93FECF99FFD5A0FFD9A7FDCD95F8EBDCFFFFFFFFFFFFFFFFFFFFFFFF
        D0F9FF25D7FF22BDF919CBFF2DC6FF13BEFF39CEFF19B6F633D0FF3BBDF31CC5
        FF6CB1C0B4905BD19753CE944FDEAB6EFFDFB9FFF5DAFAD0A1F5C48BF9C891FD
        CE98FFD49FFFD8A6FFDEADFFE2B4FFD6A4F9ECDEFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFA6F0FF15C4FF34CAFF15BAFB39D0FF20B6F330CFFF43C0F53CB2DBA89C
        79D09550CF9550D49957F9D6ADFFFBE7FFE0B9F3C288F8C78FFBCD96FFD19DFF
        D7A4FFDDABFFE1B1FFE6B8FFEFC7FDD09DFEFBF7FFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFF7AE7FF17B7F737D1FF2AB9F22DCDFF50BCE77E9989CD9450D097
        54D09754EBBF8BFFF2D7FFE4BFF7C995F7C68FFACC95FFD19CFFD6A3FFDCA9FF
        E0B0FFE5B7FFE9BDFFF1C9FFFEE1F3D0A7FFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFAFEFF4CDAFF33BAF32CC8FF76A8ABC09356D19957CE9654DFAD
        72FAD6AEFEDCB5F5C793F6C791FACD97FED19EFFD7A5FFDCACFFE0B2FFE6B8FF
        EABFFFF0C8FFFADAFFFFF1FED7ABFCF4EBFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFEDFAFF57B8D4B49768D1995ACE9756D6A163EBBF8BF6CD
        9FF5C997F5C895F9CD9BFDD2A1FFD7A8FFDDAFFFE1B6FFE7BDFFEBC2FFF2CEFF
        FBDEFFFFF2FFFFF9FBD9AFFAEEE0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFCB9B5FCF995BD29E60E2B27CEBBE89F0C593F3C9
        98F8CE9FFBD4A6FFD9ADFFDFB4FFE4BAFFE8C1FFEEC9FFF6D6FFFEE5FFFFF5FF
        FFFFFFEFD2F5DABCFEFAF5FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFE1C09AE0B17CEABF8EEFC595F2CA9DF7D0A4FAD6
        ABFFDAB2FFE0B9FFE6C0FFEBC8FFF2D4FFFAE0FFFFEDFFEAC8F2CA9BFFF5DDF5
        D9B6FCF3EAFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFBF7F2DFB380F1CEA6F6D4ADF9D9B2FEDEBAFFE5
        C2FFEACCFFF1D5FFF8E0FFFEE9FFFFF0FFFFFAFFF3D7FFC983EDA653D7A468FF
        FFFEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEDD8BFF3D2ACFDE1C2FFE8CCFFEED4FFF3
        DCFFF9E4FFFFEBFFFFF2FFFFFBFFFFFFFFFFFFF5D0A6FFC87FFFD496D58C37F7
        ECDEFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFEFDE7C7A1FFE9CEFFF3DEFFF9E6FFFF
        EDFFFFF5FFFFFBFFFFFFFFFFFFFFFAE7F5DFC5FDF7F1EDB87CFFF2C8F6BC78DC
        AB73FFFEFCFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDFBF8EDD1B0FFEAD1FFFFF6FFFF
        FFFFFFFFFFFFFFFFFFFAF8E0C5FBF3EAFFFFFFFFFFFFF9EDDEFFD19AFFF2D0DF
        A45EF4E3CDFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF8EDE0F5DFC5F9E2
        C6FAE2C7F7E1C8F9ECDDFFFFFEFFFFFFFFFFFFFFFFFFFFFFFFEEC89CFFFFEEFF
        DCB2D4A469FEFAF5FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFDF8F2F8D2A5FF
        FFF8EAC294E9CFB1FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF2D9BBFF
        FFF2FFF5DEE1BA8DFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFEFDFCF3
        D1A9F8D8B2FCF7F0FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF
        FFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFFF}
      ParentShowHint = False
      ShowHint = True
      OnClick = SpeedButtonClearClick
    end
    object EditLastName: TEdit
      Left = 133
      Top = 67
      Width = 128
      Height = 21
      TabOrder = 0
    end
    object EditBudget: TEdit
      Left = 195
      Top = 137
      Width = 96
      Height = 21
      NumbersOnly = True
      TabOrder = 1
    end
    object ComboBoxCity: TComboBox
      Left = 133
      Top = 100
      Width = 128
      Height = 21
      TabOrder = 2
    end
    object EditFirstName: TEdit
      Left = 133
      Top = 34
      Width = 128
      Height = 21
      TabOrder = 3
    end
    object ComboBoxSorting: TComboBox
      Left = 100
      Top = 272
      Width = 128
      Height = 21
      Style = csDropDownList
      TabOrder = 4
    end
    object ComboBoxOwnership: TComboBox
      Left = 133
      Top = 171
      Width = 160
      Height = 21
      Style = csDropDownList
      TabOrder = 5
    end
    object ComboBoxBudgetIneq: TComboBox
      Left = 133
      Top = 137
      Width = 48
      Height = 21
      Style = csDropDownList
      ItemIndex = 2
      TabOrder = 6
      Text = '<='
      Items.Strings = (
        '='
        '>='
        '<=')
    end
    object CheckBoxFirstNameFullMatch: TCheckBox
      Left = 265
      Top = 34
      Width = 66
      Height = 17
      Caption = 'full match'
      TabOrder = 7
    end
    object CheckBoxLastNameFullMatch: TCheckBox
      Left = 265
      Top = 69
      Width = 66
      Height = 17
      Caption = 'full match'
      TabOrder = 8
    end
    object CheckBoxCityNameFullMatch: TCheckBox
      Left = 265
      Top = 102
      Width = 66
      Height = 17
      Caption = 'full match'
      TabOrder = 9
    end
  end
end
