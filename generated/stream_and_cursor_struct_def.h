struct compound_decl_cursor
{
  compound_decl *Start;
  // TODO(Jesse)(immediate): For the love of fucksakes change these to indices
  compound_decl *At;
  compound_decl *End;
};

link_internal compound_decl_cursor
CompoundDeclCursor(umm ElementCount, memory_arena* Memory)
{
  compound_decl *Start = (compound_decl*)PushStruct(Memory, sizeof(compound_decl)*ElementCount, 1, 0);
  compound_decl_cursor Result = {
    .Start = Start,
    .End = Start+ElementCount,
    .At = Start,
  };
  return Result;
}

link_internal compound_decl
Get(compound_decl_cursor *Cursor, umm ElementIndex)
{
  Assert(ElementIndex < CurrentCount(Cursor));
  compound_decl Result = Cursor->Start[ElementIndex];
  return Result;
}

link_internal void
Set(compound_decl_cursor *Cursor, umm ElementIndex, compound_decl Element)
{
  umm CurrentElementCount = CurrentCount(Cursor);
  Assert (ElementIndex <= CurrentElementCount);

  Cursor->Start[ElementIndex] = Element;
  if (ElementIndex == CurrentElementCount)
  {
    Cursor->At++;
  }
}

link_internal compound_decl *
Push(compound_decl_cursor *Cursor, compound_decl Element)
{
  Assert( Cursor->At < Cursor->End );
  compound_decl *Result = Cursor->At;
  *Cursor->At++ = Element;
  return Result;
}

link_internal compound_decl
Pop(compound_decl_cursor *Cursor)
{
  Assert( Cursor->At > Cursor->Start );
  compound_decl Result = Cursor->At[-1];
  Cursor->At--;
  return Result;
}

link_internal s32
LastIndex(compound_decl_cursor *Cursor)
{
  s32 Result = s32(CurrentCount(Cursor))-1;
  return Result;
}

link_internal b32
Remove(compound_decl_cursor *Cursor, compound_decl Query)
{
  b32 Result = False;
  CursorIterator(ElementIndex, Cursor)
  {
    compound_decl Element = Get(Cursor, ElementIndex);
    if (AreEqual(Element, Query))
    {
      b32 IsLastIndex = LastIndex(Cursor) == s32(ElementIndex);
      compound_decl Tmp = Pop(Cursor);

      if (IsLastIndex) { Assert(AreEqual(Tmp, Query)); }
      else { Set(Cursor, ElementIndex, Tmp); }
      Result = True;
    }
  }
  return Result;
}

struct compound_decl_stream_chunk
{
  compound_decl Element;
  compound_decl_stream_chunk* Next;
};

struct compound_decl_stream
{
  memory_arena *Memory;
  compound_decl_stream_chunk* FirstChunk;
  compound_decl_stream_chunk* LastChunk;
  umm ChunkCount;
};

link_internal void
Deallocate(compound_decl_stream *Stream)
{
  Stream->LastChunk = 0;
  Stream->FirstChunk = 0;
  VaporizeArena(Stream->Memory);
}

struct compound_decl_iterator
{
  compound_decl_stream* Stream;
  compound_decl_stream_chunk* At;
};

link_internal compound_decl_iterator
Iterator(compound_decl_stream* Stream)
{
  compound_decl_iterator Iterator = {
    .Stream = Stream,
    .At = Stream->FirstChunk
  };
  return Iterator;
}

link_internal b32
IsValid(compound_decl_iterator* Iter)
{
  b32 Result = Iter->At != 0;
  return Result;
}

link_internal void
Advance(compound_decl_iterator* Iter)
{
  Iter->At = Iter->At->Next;
}

link_internal b32
IsLastElement(compound_decl_iterator* Iter)
{
  b32 Result = Iter->At->Next == 0;
  return Result;
}


link_internal compound_decl *
Push(compound_decl_stream* Stream, compound_decl Element)
{
  if (Stream->Memory == 0)
  {
    Stream->Memory = AllocateArena();
  }

  /* (Type.name)_stream_chunk* NextChunk = AllocateProtection((Type.name)_stream_chunk*), Stream->Memory, 1, False) */
  compound_decl_stream_chunk* NextChunk = (compound_decl_stream_chunk*)PushStruct(Stream->Memory, sizeof(compound_decl_stream_chunk), 1, 0);
  NextChunk->Element = Element;

  if (!Stream->FirstChunk)
  {
    Assert(!Stream->LastChunk);
    Stream->FirstChunk = NextChunk;
    Stream->LastChunk = NextChunk;
  }
  else
  {
    Stream->LastChunk->Next = NextChunk;
    Stream->LastChunk = NextChunk;
  }

  Assert(NextChunk->Next == 0);
  Assert(Stream->LastChunk->Next == 0);

  Stream->ChunkCount += 1;

  compound_decl *Result = &NextChunk->Element;
  return Result;
}



