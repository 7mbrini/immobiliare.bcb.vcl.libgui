object FormQuerySupplyAndDemand: TFormQuerySupplyAndDemand
  Left = 0
  Top = 0
  Caption = 'FormQuerySupplyAndDemand'
  ClientHeight = 581
  ClientWidth = 826
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
    Top = 539
    Width = 826
    Height = 42
    Align = alBottom
    TabOrder = 0
    object ButtonClose: TButton
      Left = 284
      Top = 10
      Width = 75
      Height = 25
      Caption = '&Close'
      TabOrder = 0
      OnClick = ButtonCloseClick
    end
  end
  object PanelClient: TPanel
    Left = 0
    Top = 0
    Width = 826
    Height = 539
    Align = alClient
    TabOrder = 1
    object PanelAssets: TPanel
      Left = 10
      Top = 274
      Width = 781
      Height = 253
      TabOrder = 0
      object Panel6: TPanel
        Left = 1
        Top = 1
        Width = 260
        Height = 251
        Align = alLeft
        TabOrder = 0
        object Label9: TLabel
          Left = 36
          Top = 114
          Width = 58
          Height = 13
          Alignment = taRightJustify
          AutoSize = False
          Caption = 'Order by :'
        end
        object Label4: TLabel
          Left = 14
          Top = 87
          Width = 80
          Height = 13
          Alignment = taRightJustify
          AutoSize = False
          Caption = 'Region :'
        end
        object Label2: TLabel
          Left = 14
          Top = 60
          Width = 80
          Height = 13
          Alignment = taRightJustify
          AutoSize = False
          Caption = 'Typology :'
        end
        object Label3: TLabel
          Left = 24
          Top = 17
          Width = 100
          Height = 16
          Caption = 'Assets Filtering'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object ComboBoxTypology: TComboBox
          Left = 104
          Top = 59
          Width = 128
          Height = 21
          Style = csDropDownList
          TabOrder = 0
        end
        object ComboBoxAssetsSorting: TComboBox
          Left = 104
          Top = 111
          Width = 128
          Height = 21
          Style = csDropDownList
          TabOrder = 1
        end
        object ComboBoxAssetsRegion: TComboBox
          Left = 104
          Top = 86
          Width = 128
          Height = 21
          Style = csDropDownList
          TabOrder = 2
        end
      end
      object Panel10: TPanel
        Left = 261
        Top = 1
        Width = 519
        Height = 251
        Align = alClient
        TabOrder = 1
        object Panel2: TPanel
          Left = 1
          Top = 1
          Width = 517
          Height = 41
          Align = alTop
          TabOrder = 0
          object LabelAssets: TLabel
            Left = 11
            Top = 15
            Width = 82
            Height = 16
            Caption = 'Assets Results'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
          end
        end
        object Panel4: TPanel
          Left = 1
          Top = 209
          Width = 517
          Height = 41
          Align = alBottom
          TabOrder = 1
          object LabelAssetsResults: TLabel
            Left = 11
            Top = 11
            Width = 298
            Height = 16
            AutoSize = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
          end
        end
        object GridAssets: TStringGrid
          Left = 1
          Top = 42
          Width = 517
          Height = 167
          Align = alClient
          TabOrder = 2
          OnDblClick = GridAssetsDblClick
        end
      end
    end
    object PanelCustomers: TPanel
      Left = 10
      Top = 10
      Width = 777
      Height = 253
      TabOrder = 1
      object Panel5: TPanel
        Left = 261
        Top = 1
        Width = 515
        Height = 251
        Align = alClient
        TabOrder = 0
        object Panel3: TPanel
          Left = 1
          Top = 209
          Width = 513
          Height = 41
          Align = alBottom
          TabOrder = 0
          object LabelCustomersResults: TLabel
            Left = 11
            Top = 11
            Width = 354
            Height = 20
            AutoSize = False
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
          end
        end
        object Panel1: TPanel
          Left = 1
          Top = 1
          Width = 513
          Height = 41
          Align = alTop
          TabOrder = 1
          object LabelCustomers: TLabel
            Left = 11
            Top = 14
            Width = 106
            Height = 16
            Caption = 'Customers Results'
            Font.Charset = DEFAULT_CHARSET
            Font.Color = clWindowText
            Font.Height = -13
            Font.Name = 'Tahoma'
            Font.Style = []
            ParentFont = False
          end
        end
        object GridCustomers: TStringGrid
          Left = 1
          Top = 42
          Width = 513
          Height = 167
          Align = alClient
          TabOrder = 2
          OnClick = GridCustomersClick
          OnDblClick = GridCustomersDblClick
          ColWidths = (
            64
            64
            64
            64
            64)
        end
      end
      object Panel7: TPanel
        Left = 1
        Top = 1
        Width = 260
        Height = 251
        Align = alLeft
        TabOrder = 1
        object Label10: TLabel
          Left = 34
          Top = 147
          Width = 58
          Height = 13
          Alignment = taRightJustify
          AutoSize = False
          Caption = 'Order by :'
        end
        object Label11: TLabel
          Left = 14
          Top = 120
          Width = 80
          Height = 13
          Alignment = taRightJustify
          AutoSize = False
          Caption = 'Region :'
        end
        object Label5: TLabel
          Left = 14
          Top = 93
          Width = 80
          Height = 13
          Alignment = taRightJustify
          AutoSize = False
          Caption = 'Budget :'
        end
        object Label8: TLabel
          Left = 14
          Top = 66
          Width = 80
          Height = 13
          Alignment = taRightJustify
          AutoSize = False
          Caption = 'Ownership :'
        end
        object Label1: TLabel
          Left = 24
          Top = 26
          Width = 124
          Height = 16
          Caption = 'Customers Filtering'
          Font.Charset = DEFAULT_CHARSET
          Font.Color = clWindowText
          Font.Height = -13
          Font.Name = 'Tahoma'
          Font.Style = [fsBold]
          ParentFont = False
        end
        object ButtonUpdate: TButton
          Left = 104
          Top = 182
          Width = 129
          Height = 27
          Caption = '&Update'
          TabOrder = 0
          OnClick = ButtonUpdateClick
        end
        object ComboBoxCustomersSorting: TComboBox
          Left = 104
          Top = 144
          Width = 128
          Height = 21
          Style = csDropDownList
          TabOrder = 1
        end
        object ComboBoxCustomersRegion: TComboBox
          Left = 104
          Top = 117
          Width = 128
          Height = 21
          Style = csDropDownList
          TabOrder = 2
        end
        object ComboBoxBudget: TComboBox
          Left = 104
          Top = 90
          Width = 128
          Height = 21
          TabOrder = 3
        end
        object ComboBoxOwnership: TComboBox
          Left = 104
          Top = 63
          Width = 128
          Height = 21
          Style = csDropDownList
          TabOrder = 4
        end
      end
    end
  end
end
